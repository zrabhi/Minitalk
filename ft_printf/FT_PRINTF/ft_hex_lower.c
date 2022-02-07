#include "printf.h"
#define xlower "0123456789abcdef"
void    ft_hex_lower(int n)
{
    //char    xlower[];   
    long nb = n; 
    if(nb <= 15)
        ft_putchar(xlower[n]);
    if(nb > 15)
    {
        ft_hex_lower((nb / 16));
        ft_hex_lower((nb % 16));
    } 
}