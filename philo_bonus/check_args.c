/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 06:26:27 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/23 15:30:22 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_check_int(char **av)
{
	long long	n;
	int			i;

	i = 1;
	while (av[i])
	{
		n = ft_atoll(av[i]);
		if (n < 0 || n > INT_MAX || ft_strlen(av[i]) >= 12)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_empty(char **av)
{
	int	i;
	int	j;
	int	empty_found;

	i = -1;
	empty_found = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && !(av[i][j] >= 9 && av[i][j] <= 13))
				break ;
			j++;
		}
		if (av[i][j] == '\0')
		{
			empty_found = 1;
			break ;
		}
	}
	if (empty_found)
		return (0);
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (printf("Please pass the allowed number of arguments. "), 0);
	if (!ft_check_empty(av))
		return (printf("Invalid argument provided ."), 0);
	if (!ft_check_int(av))
	{
		printf("Please enter a positive integer within the valid range. ");
		return (0);
	}
	return (1);
}
