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

void	reset(int *i, int *result, int pid)
{
	g_pid = pid;
	*i = 0;
	*result = 0;
}

void	sig_handler(int signum, siginfo_t *sig_info, void *b)
{
	static int	a;
	static int	j;
	(void)b;	
	if (g_pid != sig_info->si_pid)
		reset(&a, &j, sig_info->si_pid);
	if (signum == SIGUSR1)
	{
		a = (a << 1) + 1;
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
