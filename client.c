/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:03:45 by messkely          #+#    #+#             */
/*   Updated: 2024/03/05 15:34:26 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(TIME);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		if (!ft_parcing(av[1]))
		{
			write(1, "illegal pid", 11);
			return (0);
		}
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			ft_send_signal(pid, av[2][i]);
			i++;
		}
		ft_send_signal(pid, '\n');
	}
	else
	{
		write(1, "Error: wrong format.\n", 22);
		write(1, "Try: ./client <PID> <MESSAGE>\n", 31);
		return (1);
	}
	return (0);
}