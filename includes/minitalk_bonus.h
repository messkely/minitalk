/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:00:24 by messkely          #+#    #+#             */
/*   Updated: 2024/04/02 00:12:53 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# ifndef TIME
#  define TIME 450
# endif

void	ft_send_signal(int pid, char i);
void	ft_handle_signal(int signal, siginfo_t *info, void *uap);
void	ft_putnbr(int n);
int		ft_isspace(int c);
int		ft_parcing(char *str);
int		ft_atoi(const char *str);

#endif