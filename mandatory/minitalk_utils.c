/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:11:44 by messkely          #+#    #+#             */
/*   Updated: 2024/04/27 15:42:38 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) && str[i])
	{
		res = res * 10 + (str[i] - 48);
		if (0 > res && sign == -1)
			return (0);
		else if (0 > res && sign == 1)
			return (-1);
		i++;
	}
	return (sign * res);
}

void	ft_putnbr(int n)
{
	if (n < 10)
		write(1, &"0123456789"[n], 1);
	else
	{
		ft_putnbr(n / 10);
		write(1, &"0123456789"[n % 10], 1);
	}
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_parcing(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) || ft_isalpha(str[i]))
			return (0);
		else if (str[i] == '+')
			return (0);
		i++;
	}
	return (1);
}
