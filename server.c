/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:41:25 by zrabhi            #+#    #+#             */
/*   Updated: 2022/02/12 17:39:06 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	g_pid;

void	reset1(char *c, int *j)
{
	*j = 0;
	*c = 0;
}

void	reset2(int pid)
{
	g_pid = pid;
}

void	sig_handler(int signum, siginfo_t *sig_info, void *b)
{
	static char	a;
	static int	j;

	b = NULL;
	if (g_pid != sig_info->si_pid)
	{
		reset1(&a, &j);
		reset2(sig_info->si_pid);
	}
	if (signum == SIGUSR1)
	{
		a = (a << 1) | 1;
		j++;
	}
	if (signum == SIGUSR2)
	{
		a = (a << 1);
		j++;
	}	
	if (j >= 8)
	{
		ft_putchar(a);
		reset1(&a, &j);
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
