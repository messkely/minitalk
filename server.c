/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:04:35 by messkely          #+#    #+#             */
/*   Updated: 2024/02/19 21:58:40 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putnbr(int n)
{
    if (n < 10)
        write(1, &"0123456789"[n], 1);
    else
    {
        ft_putnbr(n / 10);
        write(1, &"0123456789"[n%10], 1);
    }
}

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

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		write(1, "Error: wrong format.\n", 22);
		write(1, "Try: ./server\n", 15);
		return (0);
	}
	pid = getpid();
	write(1, "PID->", 6);
	ft_putnbr(pid);
	write(1, "\nWaiting for a message...\n", 26);
	while (ac == 1)
	{
		signal(SIGUSR1, ft_handle_signal);
		signal(SIGUSR2, ft_handle_signal);
		pause ();
	}
	return (0);
	}