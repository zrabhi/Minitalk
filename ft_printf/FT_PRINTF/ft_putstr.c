//#include "printf.h"
#include <unistd.h>
static size_t ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i); 
}
void    ft_putstr(const char *str)
{
    int i;
    i = -1;
    if(str)
    {
        while(str[i++])
            write(1, &str[i], 1);
    }
}
int main()
{
    ft_putstr("hello world");
}