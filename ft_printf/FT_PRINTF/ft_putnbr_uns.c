#include "printf.h"

void ft_putnbr_uns(unsigned int nb)
{
    if(nb <= 9 )
        ft_putchar((nb + '0'));
    if( nb > 9 )
    {
        ft_putnbr_uns(nb / 10);
        ft_putnbr_uns(nb % 10);
    }
}