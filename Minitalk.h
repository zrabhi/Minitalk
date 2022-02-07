#ifndef MINITALK_H
#define MINITALK_H
 

#include <unistd.h>
#include <sys/signal.h>
#include <signal.h>
#include <stdlib.h>

void    send_char(char c, int pid);
void    client_message(char *str, int pid);
void sig_h(int signum);
void ft_putchar(char c);
#endif
