#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#define XUPPERR "0123456789ABCDEF"
#define xlower "0123456789abcdef"

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void    ft_putchar(char c, int *count);
void    ft_hex_lower(unsigned int n, int *count);
void    ft_putstr(const char *str, int *count);
void    ft_putnbr(int n, int *count);
void    ft_putnbr_uns(unsigned int nb, int *count);
void    ft_hex_upper(unsigned int n, int *count);
void ft_add(unsigned long n, int *count);
int     ft_printf(const char *format, ...);
void    ft_print_p(unsigned long n, int *count);
//void ft_print(va_list ap, char c, int *count);

#endif