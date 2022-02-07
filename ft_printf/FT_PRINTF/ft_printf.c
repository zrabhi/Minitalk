#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf.h"
static void ft_print(va_list ap, char c)
{ if(c)
{ 
      if(c == 'c')
            ft_putchar(va_arg(ap, char));
      else if( c == 's')
            ft_putstr(va_arg(ap, char *));
     else if(c == 'p')
          ft_print_adress(va_arg(ap, int));
      else if(c == 'd' || c == 'i')
            ft_putnbr(va_arg(ap, int));
      else if(c == 'u')
            ft_putnbr_uns(va_arg(ap, unsigned int));
      else if(c == 'x')
            ft_hex_lower(va_arg(ap, int));
      else if(c == 'X')
            ft_hex_upper(va_arg(ap, int));
      else if(c == '%')
            ft_putchar('%');
}
}
int ft_printf(const char *format, ...)
{
      int i;

      va_list ap;
      va_start(ap, format);

      i = 0;
      while(format[i])
      {
            if(format[i] == '%')
            {
                  i++;
                  ft_print(ap, format[i]);
                  //i++;           
            }
           else if (format[i] != '%')
            {
                  ft_putchar(format[i]);
            }
           /* else if(format[i] == '#' && format[i + 1] == '%')
                  {
                        ft_putchar(0);
                      ft_putchar(x);
                        i++;
                        //ft_hex_upper(ap, format[i]);
                  } */
      i++;
      }
      va_end(ap);
}
#include <stdio.h>
int main()
{
  //int i =2000;
  //int k = 2000;
      int a = 11;
    //char *p = &a;
      //ft_printf("%x", -2000);
      ft_printf("%d", ft_printf("%d", 1234));
      //printf("%d", printf("%s", "hello world"));
    //return(0);
}