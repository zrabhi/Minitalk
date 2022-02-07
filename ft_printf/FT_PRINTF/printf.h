#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define XUPPERR "0123456789ABCDEF"
#define xlower "0123456789abcdef"

void    ft_putchar(char c);
void    ft_hex_lower(int n);
void    ft_putstr(char *str);
void    ft_putnbr(int n);
void    ft_putnbr_uns(unsigned int nb);
void    ft_hex_upper(int n);
int     ft_printf(const char *format, ...);
void    ft_print_adress(int n);

#endif