/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:45:59 by zrabhi            #+#    #+#             */
/*   Updated: 2022/02/15 19:46:04 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

int	g_pid;

void	reset(int pid)
{
	g_pid = pid;
}

void	sig_handler(int signum, siginfo_t *sig_info, void *b)
{
	char	a;
	static char last_char;
	static int	j;
	const char back_space = 8;
	(void)b;	
	if (g_pid != sig_info->si_pid)
	{
		if((last_char >> 8) | 1)
			write(1, &back_space, 1);
		 a = 0;
		 j = 0;
		 reset(sig_info->si_pid);
	}
	if (signum == SIGUSR1)
	{
		//write(1, "hey", 3);
		a = (a << 1) | 1;
		j++;                 
	}
	if(signum == 31)
	{
		a = (a << 1);
		j++;
	}
	if(j >= 8)
	{
		ft_putchar(a);
		last_char = a;
		a = 0;
		j = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = SA_SIGINFO;
	sa.__sigaction_u.__sa_sigaction = &sig_handler;
	pid = getpid();
	write(1, "SERVER PID : ", 14);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
