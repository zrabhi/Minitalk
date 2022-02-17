/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:39:59 by zrabhi            #+#    #+#             */
/*   Updated: 2022/02/16 18:50:45 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	send_char(char c, int pid)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if (1 & (c >> bit))
		{
			if (kill(pid, SIGUSR1) == -1)
				write(1, "Failed to setuo signal", 23);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				write(1, "Failed to setup signal", 23);
		}
		usleep(600);
		bit--;
	}
}

void	recieved(void)
{
	write(1, "signal is recieved succesfully\n", 32);
}

void	client_message(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_char(str[i], pid);
	recieved();
}

void	invalid(void)
{
	write(1, "Invalide parametrs\n", 19);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*our_msg;

	if (argc != 3)
		invalid();
	pid = ft_atoi(argv[1]);
	our_msg = argv[2];
	client_message(our_msg, pid);
}
