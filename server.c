#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "Minitalk.h"


size_t ft_strlen(char *str)
{
  int i;

  i = 0;
  while(str[i])
      i++;
  return(i);
}
void sig_h(int signum)
{
  static int a;
  static int j;
  if (signum == SIGUSR1)
    { 
       a = (a<<1)+1;
        //j++;
    }
    if (signum == SIGUSR2)
    { 
        a = (a<<1);
        //j++;
    }
  j++;
  if(j >= 8)
  { 
    ft_putchar(a);
    a = 0;
    j = 0;
    //a = 0;
  }
}
int main()
{
  char *pid = ft_itoa(getpid());

//   void (*f)(int);
//    f = &huu;
  write(1, "SERVER PID : ", 13);
  write(1, pid, ft_strlen(pid));
  write(1, "\n", 1);
  free(pid);
  while (1)
  {
    signal(SIGUSR1, &sig_h);
    signal(SIGUSR2, &sig_h);
      // sigaction(SIGUSR1, &sig_h, NULL);
      // sigaction(SIGUSR2, &sig_h, NULL);
      pause();
  }
}
