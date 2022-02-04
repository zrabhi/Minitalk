#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>
#include <signal.h>
#include <stdlib.h>

void send_char(char c, int pid)
{
  int bit = -1;
  while (++bit < 7)
  {
    if (1 & (c >> bit))
    {
      // printf("1");
      kill(pid, SIGUSR1);
    }
    else
    {
      // printf("0");
      kill(pid, SIGUSR2);
    }
    usleep(500);
  }
}


 int main(int argc, char **argv)
{
  int pid = atoi(argv[1]);
  // send_char('A', pid);
  // send_char('B', pid);
   kill(pid, SIGABRT);
}