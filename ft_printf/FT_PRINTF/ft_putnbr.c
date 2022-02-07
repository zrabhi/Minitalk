#include "printf.h"
static int count(long nb)
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

int ft_putnbr(int n)
{
    long int nb;
    int l;
    nb = n;
    l = count(nb);
    if(nb < 0)
    { 
        ft_putchar('-');
        nb = nb * - 1;
    }
    if(nb <= 9)
        ft_putchar((nb + 48));
    if(nb > 9)
    {
        ft_putnbr((nb / 10));
        ft_putnbr((nb % 10));
    }
    return (l);
}
int main()
{
    int nb = -123456780;
    printf("%d", ft_putnbr("%d", nb));
}