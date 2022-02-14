    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:40:59 by zrabhi            #+#    #+#             */
/*   Updated: 2022/02/12 15:41:03 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
#define MINITALK_H
 

#include <unistd.h>
#include <sys/signal.h>
#include <signal.h>
#include <stdlib.h>

void    send_char(char c, int pid);
int     ft_atoi(const char *str);
void    client_message(char *str, int pid);
void sig_h(int signum);
void ft_putchar(char c);
void ft_putnbr(int n);
void	ft_bzero(void *s, size_t n);
size_t  ft_strlen(char *str);
#endif
