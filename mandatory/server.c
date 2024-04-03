/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:04:35 by messkely          #+#    #+#             */
/*   Updated: 2024/04/01 23:44:46 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_handle_signal(int signal, siginfo_t *info, void *uap)
{
	static int		bit;
	static int		c;
	static pid_t	pid;

	uap = NULL;
	c |= (signal == SIGUSR1);
	if (pid != info->si_pid)
	{
		c = 0;
		bit = 0;
	}
	if (++bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	else
		c <<= 1;
	pid = info->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	sig.sa_sigaction = ft_handle_signal;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = getpid();
	write(1, "PID->", 6);
	ft_putnbr(pid);
	write(1, "\nWaiting for a message...\n", 26);
	while (1)
		pause ();
	return (0);
}
