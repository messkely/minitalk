/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:03:45 by messkely          #+#    #+#             */
/*   Updated: 2024/04/02 21:46:51 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	ft_error(int pid)
{
	write(1, "This pid not found : ", 22);
	ft_putnbr(pid);
	write(1, "\n", 1);
	exit(1);
}

void	ft_send_signal(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(pid);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error(pid);
		}
		usleep(TIME);
		bit--;
	}
}

static int	ft_isempty(const char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (!ft_isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int				pid;
	int				i;

	i = 0;
	if (ac == 3)
	{
		if (!ft_parcing(av[1]))
		{
			write(1, "illegal pid", 11);
			return (0);
		}
		pid = ft_atoi(av[1]);
		if (ft_isempty(av[2]))
		{
			kill(pid, SIGTERM);
			exit(0);
		}
		while (av[2][i] != '\0')
			ft_send_signal(pid, av[2][i++]);
		ft_send_signal(pid, '\n');
		ft_send_signal(pid, '\0');
	}
	else
		write(1, "Error: wrong format.\nTry: ./client <PID> <MESSAGE>\n", 51);
	return (0);
}
