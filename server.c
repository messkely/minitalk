/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:04:35 by messkely          #+#    #+#             */
/*   Updated: 2024/02/20 12:09:37 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle_signal(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

// int	main(void)
// {
// 	int	pid;
// 	struct sigaction sig;
	

// 	pid = getpid();
// 	write(1, "PID->", 6);
// 	ft_putnbr(pid);
// 	write(1, "\nWaiting for a message...\n", 26);
// 	sig.sa_sigaction = ft_handle_signal;
// 	while (1)
// 	{
// 		sigaction(SIGUSR1, &sig, NULL);
// 		sigaction(SIGUSR2, &sig, NULL);
// 		pause ();
// 	}
// 	return (0);
// }
int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "PID->", 6);
	ft_putnbr(pid);
	write(1, "\nWaiting for a message...\n", 26);
	while (1)
	{
		signal(SIGUSR1, ft_handle_signal);
		signal(SIGUSR2, ft_handle_signal);
		pause ();
	}
	return (0);
}