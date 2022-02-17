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


SRC_CLIENT = client.c ft_atoi.c ft_putnbr.c ft_putchar.c

SRC_SERVER =  server.c ft_atoi.c  ft_putnbr.c ft_putchar.c

OBG_CLIENT = $(SRC_CLIENT:.c=.o)

OBG_SERVER = $(SRC_SERVER:.c=.o)

SRC_CLIENT_BONUS = client_bonus.c ft_atoi.c ft_putnbr.c ft_putchar.c

SRC_SERVER_BONUS = server_bonus.c ft_atoi.c   ft_putnbr.c ft_putchar.c

OBG_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

OBG_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

GCC_FLAGS = -Wall -Wextra -Werror

CC = cc

CLIENT = client

ClIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

SERVER = server

NAME = client_server

all : $(NAME)

$(NAME) : $(OBG_CLIENT) $(OBG_SERVER)
	$(CC) $(GCC_FLAGS) -o $(CLIENT) $(OBG_CLIENT) 
	$(CC) $(GCC_FLAGS) -o $(SERVER) $(OBG_SERVER)

%.o : %.c
	$(CC) $(GCC_FLAGS) -c $<

bonus : $(OBG_CLIENT_BONUS) $(OBG_SERVER_BONUS)
	$(CC) $(GCC_FLAGS) -o $(ClIENT_BONUS) $(OBG_CLIENT_BONUS) 
	$(CC) $(GCC_FLAGS) -o $(SERVER_BONUS) $(OBG_SERVER_BONUS)

clean :
	rm -f $(OBG_SERVER) $(OBG_CLIENT) $(OBG_CLIENT_BONUS) $(OBG_SERVER_BONUS)

fclean : clean
	rm -f $(CLIENT) $(SERVER) $(ClIENT_BONUS) $(SERVER_BONUS)

re : fclean all