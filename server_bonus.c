/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:45:59 by zrabhi            #+#    #+#             */
/*   Updated: 2022/02/16 19:22:09 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	g_pid;

typedef struct variabls {
	int				j;
	char			a;
	char			back_space;
	char			last_char;
}	t_variabls;

void	reset1(char *i, int *j)
{
	*i = 0;
	*j = 0;
}

void	reset2(char *i, int *j, int pid)
{
	g_pid = pid;
	*i = 0;
	*j = 0;
}

void	back_space(void)
{
	int	back_space;

	back_space = 8;
	write(1, &back_space, 1);
}

void	sig_handler(int signum, siginfo_t *sig_info, void *b)
{
	static t_variabls	vb;

	b = NULL;
	if (g_pid != sig_info->si_pid)
	{
		if ((vb.last_char >> 8) | 1)
			back_space();
		reset2(&vb.a, &vb.j, sig_info->si_pid);
	}
	if (signum == SIGUSR1)
	{
		vb.a = (vb.a << 1) | 1;
		vb.j++;
	}
	if (signum == SIGUSR2)
	{
		vb.a = (vb.a << 1);
		vb.j++;
	}
	if (vb.j >= 8)
	{
		ft_putchar(vb.a);
		vb.last_char = vb.a;
		reset1(&vb.a, &vb.j);
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
