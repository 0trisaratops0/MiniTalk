NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT = client
SERVER = server

all: $(NAME)

$(SERVER): $(SERVER).c minitalk.h
			@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER).c

$(CLIENT): $(CLIENT).c minitalk.h
			@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT).c

$(NAME): $(SERVER) $(CLIENT)

clean:
		@$(RM) $(CLIENT) $(SERVER)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
