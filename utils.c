/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:08:55 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/04 12:57:44 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_error_exit(char *msg, int n)
{
        write(2, "Error\n", 7);
        write(2 ,msg, ft_strlen(msg));
        exit(n);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nb;
	char	*s;

	s = (char *)str;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	sign = 1;
	if (s[i] == '-')
		sign *= -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	nb = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (sign * nb);
}

int  ft_strlen(const char *s)
{
        int  i;

        i = 0;
        while (s[i] != '\0')
			i++;
        return (i);
}
long long	ft_time_in_ms(struct timeval *time)
{
	return (time->tv_sec * 1000 + time->tv_usec / 1000);
}