/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:00:24 by messkely          #+#    #+#             */
/*   Updated: 2024/03/06 09:44:21 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>

# ifndef TIME
#  define TIME 450
# endif

void	ft_send_signal(int pid, char i);
void	ft_handle_signal(int signal, siginfo_t *info, void *s);
void	ft_putnbr(int n);
int		ft_parcing(char *str);
int		ft_atoi(const char *str);

#endif