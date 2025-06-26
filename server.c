/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 15:35:19 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/05/21 16:40:31 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	len = 0;
	if (fd < 0 || !str)
		return ;
	while (str[len])
		len++;
	write(fd, str, len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		write(fd, "-", 1);
		n_long *= -1;
	}
	if (n_long < 10)
		ft_putchar_fd(n_long + '0', fd);
	else
	{
		ft_putnbr_fd(n_long / 10, fd);
		ft_putchar_fd(n_long % 10 + '0', fd);
	}
}

void	signal_handler(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("It seems you have enterred wrong data, try again!", 1);
		return (1);
	}
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause ();
	}
	return (0);
}
