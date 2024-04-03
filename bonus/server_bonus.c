/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:04:31 by messkely          #+#    #+#             */
/*   Updated: 2024/04/02 00:12:16 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	ft_handle_signal(int signal, siginfo_t *info, void *uap)
{
	static int		bit;
	static char		c;
	static int		pid;

	(void)uap;
	if (pid != info->si_pid)
	{
		c = 0;
		bit = 0;
	}
	c |= (signal == SIGUSR1);
	if (++bit == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(pid, SIGUSR1);
		c = 0;
		bit = 0;
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
