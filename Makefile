# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 15:37:19 by zrabhi            #+#    #+#              #
#    Updated: 2022/02/12 15:38:28 by zrabhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_putchar.c ft_putnbr.c ft_atoi.c ft_strlen.c ft_bzero.c
CC = gcc
GCC_FLAGS = -wall -wextra -werror
server = server
client = client

all : 
	$(CC) $(GCC) $(SRC) server.c -o $(server)
	$(CC) $(GCC) $(SRC) client.c -o $(client)
bonus :
	$(CC) $(GCC) $(SRC) server_bonus.c -o server_bns
	$(CC) $(GCC) $(SRC) client_bonus.c -o client_bns
