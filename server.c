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
    ft_putchar(a);
    a = 0;
    j = 0;

  }
}
int main()
{
  struct sigaction	sa;

	sa.sa_handler = &sig_h;
	sa.sa_flags = SA_RESTART;
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa, NULL);
  int pid = getpid();
   write(1, "SERVER PID : ", 14);
  ft_putnbr(pid);
  write(1, "\n", 1);
  while (1)
  {
    // sigaction(SIGUSR1, &sig_h, NULL);
    // sigaction(SIGUSR2, &sig_h, NULL);
    // signal(SIGUSR1, %sig_h):
    // sigaction(SIGUSR2, &sa, NULL);
    pause();
  }
}
