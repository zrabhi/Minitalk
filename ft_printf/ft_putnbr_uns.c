#include "ft_printf.h"

void ft_putnbr_uns(unsigned int nb, int *count)
{
    if(nb <= 9 )
        ft_putchar((nb + '0'), count);
    if( nb > 9 )
    {
        ft_putnbr_uns((nb / 10), count);
        ft_putnbr_uns((nb % 10), count);
    }
}