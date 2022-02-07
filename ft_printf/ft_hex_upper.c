
#include "ft_printf.h"


#define XUPPERR "0123456789ABCDEF"

void    ft_hex_upper(unsigned int n, int *count)
{
    if(n < 16)
        ft_putchar((XUPPERR[n]), count);
    if(n >= 16)
    {
        ft_hex_upper((n / 16), count);
        ft_hex_upper((n % 16), count);
    } 
}