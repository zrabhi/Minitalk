#include "printf.h"

void    ft_print_adress(int n)
{
    long nb = n;
    write(1, "0x", 2);
    if(XUPPERR)
        ft_hex_upper(n);
    else 
        ft_hex_lower(n);
}