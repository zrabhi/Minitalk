SRC =  ft_putnbr_uns.c ft_putchar.c ft_putnbr.c  ft_hex_upper.c ft_hex_lower.c ft_putstr.c ft_printf.c \
		ft_print_adress.c
OBJ = $(SRC:.c=.o)
CC = gcc
GCC_FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
AR = ar rc
NAME = ft_printf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c

	$(CC) $(GCC FLAGS) -c $<
clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ) $(NAME)
re: fclean all 
