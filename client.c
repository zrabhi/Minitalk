#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>
#include <signal.h>
#include <stdlib.h>
#include "Minitalk.h"

void send_char(char c, int pid)
{
  int bit = 7;
  while (bit !=-1)
  {
    if (1 & (c >> bit))
    {
      ft_putchar('1');
      kill(pid, SIGUSR1);
    }
    else
    {
       write(1,"0",1);
      kill(pid, SIGUSR2);
    }
    usleep(500);
    bit--;
    // if( bit == 0)
    //   write(1, &c, 1);
  }
}
void  client_message(char *str, int pid)
{
      int i;

       i = -1;
       while(str[++i])
            send_char(str[i], pid);
}


 int main(int argc, char **argv)
{
  char *our_msg;
  int pid = atoi(argv[1]);
  char s[] = "hello world"; 
  our_msg = argv[2];
  client_message(our_msg, pid);
  //  kill(pid, SIGABRT);
}