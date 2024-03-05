/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:09:12 by messkely          #+#    #+#             */
/*   Updated: 2024/02/20 12:09:59 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
    if (n < 10)
        write(1, &"0123456789"[n], 1);
    else
    {
        ft_putnbr(n / 10);
        write(1, &"0123456789"[n%10], 1);
    }
}