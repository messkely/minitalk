/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:04:31 by messkely          #+#    #+#             */
/*   Updated: 2024/02/29 12:02:33 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handle_signal(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)s;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	int	pid;
	struct sigaction sig;

	pid = getpid();
	write(1, "PID->", 6);
	ft_putnbr(pid);
	write(1, "\nWaiting for a message...\n", 26);
	sig.sa_sigaction = ft_handle_signal;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause ();
	}
	return (0);
}