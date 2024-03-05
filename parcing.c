/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messkely <messkely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:11:52 by messkely          #+#    #+#             */
/*   Updated: 2024/03/05 15:25:59 by messkely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

static int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ft_parcing(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (ft_isspace(str[i]))
            return (0);
        else if (ft_isalpha(str[i]))
            return (0);
        else if (str[i] == '+')
            return (0);
        i++;
    }
    return (1);
}