/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:04:30 by messkely          #+#    #+#             */
/*   Updated: 2024/03/06 09:45:04 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

# ifndef TIME
#  define TIME 450
# endif

void	ft_send_signal(int pid, char i);
void	ft_handle_signal(int signal);
void	ft_putnbr(int n);
int		ft_parcing(char *str);
int		ft_atoi(const char *str);

#endif
