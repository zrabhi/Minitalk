#include "ft_printf.h"

void ft_add(unsigned long n, int *count)
{
   if(n <=15)
        ft_putchar(xlower[n], count);
    if(n >= 16)
    {
        ft_add((n / 16), count);
        ft_add((n % 16), count);
    } 
}