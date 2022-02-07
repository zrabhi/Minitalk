#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
 void ft_print(va_list ap, char c, int *count)
{ 
      if(c == 'c')
            ft_putchar(va_arg(ap, int), count);
      else if( c == 's')
            ft_putstr(va_arg(ap, char *), count);
     else if(c == 'p')
          ft_print_p(va_arg(ap, unsigned long), count);
      else if(c == 'd' || c == 'i')
            ft_putnbr(va_arg(ap, int), count);
      else if(c == 'u')
            ft_putnbr_uns(va_arg(ap, unsigned int), count);
      else if(c == 'x')
            ft_hex_lower(va_arg(ap, unsigned int), count);
      else if(c == 'X')
            ft_hex_upper(va_arg(ap, unsigned int), count);
      else if(c == '%')
            ft_putchar('%', count);
}

int ft_printf(const char *format, ...)
{
      int i;
      int count;

      va_list ap;
      va_start(ap, format);

      count = 0;
      i = 0;
      while (format[i])
      {
            if (format[i] == '%')
            {
                 i++;
                 ft_print(ap, format[i], &count);
                  //i++;
                  //count +=1;       
            }
           else
            {
                  ft_putchar(format[i], &count);
            }
      i++;
      }
      va_end (ap);
      return (count);
}
#include <limits.h>
#include <stdio.h>
/*int main()
{
      unsigned long a = ULONG_MAX;
      unsigned long b = -ULONG_MAX;
      ft_printf("%p\n", b);
      ft_printf("%p", a);
}*/