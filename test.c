#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void bits(char bit)
{
    int plus = -1;
     while(++plus < 7 )
     {
         if((1 &(bit >> plus)) == 1)
                write(1, "1", 1);
        else if((1&(bit >> plus))== 0)
                 write(1, "0", 1);
        //  putchar(1 & (plus >> bit) ? '1' : '0');        
     }
     write(1, "\n", 1);
}
int main()
{
    int i = 2;
    int result = 1 >> 0;
    bits('a');
}