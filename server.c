#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "Minitalk.h"

void sig_h(int signum)
{
  static int a;
  static int j;
  if (signum == SIGUSR1)
    { 
       a = (a<<1)+1;
        j++;
    }
    if (signum == SIGUSR2)
    { 
        a = (a<<1);
        j++;
    }
  if(j >= 8)
  {
  //  
  // 
  ft_putchar(a);
    j = 0;
    a = 0;
  }
}
int main()
{
  int pid = getpid();
//   int t = 7;

//   void (*f)(int);
//    f = &huu;
  printf("SERVER PID: %d\n", pid);
//   signal(SIGUSR1, f);
// signal(SIGUSR2, f);
  while (1)
  {
      signal(SIGUSR1, &sig_h);
      signal(SIGUSR2, &sig_h);
      pause();
  }
}
