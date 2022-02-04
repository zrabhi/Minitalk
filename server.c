#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void huu(int i)
{

    if (i == SIGUSR1)
         write(1,"1",1);
    else if (i == SIGUSR2)
         write(1,"0",1);
    else 
         write(1,"taha",4);

}
int main()
{
  int k = getpid();
  int t = 7;

  void (*f)(int);
   f = &huu;
  printf("PID: %d\n", k);
  int i = 0;
  while (1)
  {
    signal(SIGUSR1, f);
    signal(SIGUSR2, f);
    signal(SIGABRT, f);
    // if(!i)
    //   {
    //   printf("\n");
    //   printf("\n");
    //     i = 1;
    //   }
   pause();
  }
}