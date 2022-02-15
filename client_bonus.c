#include "Minitalk.h"

// int bit = 7;

void send_char(char c, int pid)
{
	 int bit = 7 ;
	while (bit != -1)
	{
		// if (kill(pid, 1 & (c >> bit) ?   SIGUSR1 : SIGUSR2) == -1)
				// write(1, "Failed to setup signal", 23);
    	if (1 & (c >> bit))
    	{
			
      		if(kill(pid, SIGUSR1) == -1)
        		  write(1 ,"Failed to setuo signal", 23);
			// write(1, "1", 1);
    	
		}
    	else 
    	{
      		if(kill(pid, SIGUSR2)== -1)
        			write(1 ,"Failed to setup signal", 23);
			// write(1, "0", 1);
    	}
    usleep(600);
    bit--;
	}
}
void	recieved(void)
{
    write(1, "signal is recieved succesfully\n", 32);
}

void  client_message(char *str, int pid)
{
		int i;

		i = -1;
		while(str[++i])
		{
			send_char(str[i], pid);
		}
		recieved();
	
}
void 	invalid(void)
{
	write(1, "Invalide parametrs\n", 19);
	exit(EXIT_FAILURE);
}
int main(int argc, char **argv)
{
	 char *our_msg;
	 int pid;

	if(argc != 3)
		invalid();
  	pid = ft_atoi(argv[1]);
 	our_msg = argv[2];
 	client_message(our_msg, pid);
}
