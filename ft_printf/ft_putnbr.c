#include "ft_printf.h"
static int len(long nb)
{
    int count;

    count = 0;
    if(nb < 0)
        count = 1;
    while(nb != 0)
    {
        nb /= 10;
        count++;
    }
    return(count);
}

void ft_putnbr(int n, int *count)
{
    long int nb;
    //int l;
    nb = n;
   // l = len(nb);
    if(nb < 0)
    { 
        ft_putchar('-', count);
        nb = nb * - 1;
    }
    if(nb <= 9)
        ft_putchar((nb + 48), count);
    if(nb > 9)
    {
        ft_putnbr((nb / 10), count);
        ft_putnbr((nb % 10), count);
    }
    //return (l);
}
/*int main()
{
    int nb = -123456780;
    printf("%d", ft_putnbr("%d", nb));
}*/