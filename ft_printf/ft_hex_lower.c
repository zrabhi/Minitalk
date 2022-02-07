#include "ft_printf.h"
#define xlower "0123456789abcdef"
void    ft_hex_lower(unsigned int n, int *count)
{ 

    if(n <=15)
        ft_putchar(xlower[n], count);
    if(n >= 16)
    {
        ft_hex_lower((n / 16), count);
        ft_hex_lower((n % 16), count);
    } 
}