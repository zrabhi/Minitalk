SRC =   ft_putchar.c ft_putnbr_uns.c  ft_putnbr.c  ft_hex_upper.c ft_hex_lower.c ft_putstr.c ft_printf.c \
		ft_print_adress.c ft_add.c
OBJ = $(SRC:.c=.o)
CC = gcc
GCC_FLAGS = -Wall -Wextra -Werror
##HEADER = ft_printf.h
AR = ar rc
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c ft_printf.h

	$(CC) $(GCC FLAGS) -c $<
clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ) $(NAME)
re: fclean all 
