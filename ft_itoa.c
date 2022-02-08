#include "Minitalk.h"
static int	count(long c)
{
	int	count;

	count = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		count = 1;
	while (count >= 0)
	{
		while (c != 0)
		{
			c /= 10;
			count++;
		}
		return (count);
	}
	return (0);
}

char	*ft_itoa(int c)
{
	int		i;
	long	nb;
	char	*str;

	nb = c;
	i = count(nb);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	if (nb == 0)
		str[0] = '0';
	str[i--] = '\0';
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb /= 10;
		i--;
	}
	return (str);
}