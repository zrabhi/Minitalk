#include "ft_printf.h"
#include <unistd.h>
void	ft_putstr(const char *str, int *count)
{
	int	i;

	if (str == NULL)
		ft_putstr("(null)", count);
	else
	{
		i = 0;
		while (str[i])
			ft_putchar(str[i++], count);
	}
}