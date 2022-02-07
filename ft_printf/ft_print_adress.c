#include "ft_printf.h"

void    ft_print_p(unsigned long n, int *count)
{
    ft_putchar('0', count);
    ft_putchar('x', count);
   /*if(n < 16)
        ft_putchar(xlower[n], count);
    if(n >= 16)
    {
        ft_print_adress((n / 16), count);
        ft_print_adress((n % 16), count);
    } 
    else 
        ft_putchar(xlower[n], count);*/
    ft_add(n, count);
}