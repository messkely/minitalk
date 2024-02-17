/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:04:35 by messkely          #+#    #+#             */
/*   Updated: 2024/02/17 20:52:57 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void handle_signal(int signal)
// {
//  static unsigned char current_char;
//  static int    bit_index;

//  current_char |= (signal == SIGUSR1);
//  bit_index++;
//  if (bit_index == 8)
//  {
//   if (current_char == END_TRANSMISSION)
//    printf("\n");
//   else
//    printf("%c", current_char);
//   bit_index = 0;
//   current_char = 0;
//  }
//  else
//   current_char <<= 1;
// }

// int main()
// {
//     int id;

//     id = (int)(getpid());
//     printf("%d\n", id);
// }

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
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
		printf("\033[91mError: wrong format.\033[0m\n");
		printf("\033[33mTry: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	printf("\033[90mWaiting for a message...\033[0m\n");
	while (ac == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause ();
	}
	return (0);
}