
#include "printf.h"


#define XUPPERR "0123456789ABCDEF"

void    ft_hex_upper(int n)
{
   // char    XUPPERR;
    long nb = n; 
    if(nb <= 15)
        ft_putchar((XUPPERR[n]));
    if(nb > 15)
    {
        ft_hex_upper((nb / 16));
        ft_hex_upper((nb % 16));
    } 
}