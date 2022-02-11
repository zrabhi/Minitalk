#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "Minitalk.h"

int g_pid = 0;

void	(int *i, int *result, int pid)
{
	g_pid = pid;
	*i = 0;
	*result = 0;
}
void sig_handler(int signum, siginfo_t *sig_info, void *b)
{
   static int a;
   static int j;
   (void)b;
   if (g_pid != sig_info->si_pid)
		reset(&a, &j, sig_info->si_pid);
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

 int pid = getpid();
   write(1, "SERVER PID : ", 14);
  ft_putnbr(pid);
  write(1, "\n", 1);
	sa.__sigaction_u.__sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa, NULL);
  while (1)
  {
    // sigaction(SIGUSR1, &sig_h, NULL);
    // sigaction(SIGUSR2, &sig_h, NULL);
    // signal(SIGUSR1, %sig_h):
    // sigaction(SIGUSR2, &sa, NULL);
    pause();
  }
}
