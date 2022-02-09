SRC = ft_putchar.c ft_putnbr.c ft_itoa.c ft_strlen.c ft_bzero.c
CC = gcc
GCC_FLAGS = -wall -wextra -werror

all: 
	$(CC) $(GCC) $(SRC) server.c -o server
	$(CC) $(GCC) $(SRC) client.c -o client