/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <sjeddi@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/14 18:55:41 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/05/21 16:42:53 by sjeddi        ########   odam.nl         */
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
		len ++;
	write(fd, str, len);
}

static int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	signal_action(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Error: input needs to be formatted as <pid> <string>", 1);
		return (1);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			signal_action(pid, argv[2][i]);
			i++;
		}
		signal_action(pid, '\n');
	}
	return (0);
}
