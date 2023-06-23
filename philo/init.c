/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:56:32 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/23 20:40:26 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_philo *philo, t_data *data, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		philo[i].philo_num = i + 1;
		philo[i].data = data;
		philo[i].last_meal_time = 0;
		philo[i].r_fork = (philo[i].philo_num) % num_of_philos;
		philo[i].l_fork = (philo[i].philo_num - 1) % num_of_philos;
		philo[i].meals_count = data->must_eat;
		i++;
	}
}

int	init_philo_data(t_data *data, char **av, int ac)
{
	data->num_of_philos = ft_atoll(av[1]);
	if (data->num_of_philos == 0)
		return (0);
	data->time_to_die = ft_atoll(av[2]);
	data->time_to_eat = ft_atoll(av[3]);
	data->time_to_sleep = ft_atoll(av[4]);
	data->ac = ac;
	if (pthread_mutex_init(&data->last_meal_mutex, NULL))
		ft_error("failed to initialize mutex");
	data->death = 0;
	if (ac == 6)
	{
		data->eaten_meals = 0;
		data->must_eat = ft_atoll(av[5]);
		if (data->must_eat == 0)
			return (0);
		if (pthread_mutex_init(&data->eaten_meals_mutex, NULL))
			ft_error("failed to initialize mutex");
	}
	return (1);
}

int	init_forks(t_data *data)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	data->forks = forks;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (ft_error("failed to initialize mutex"), 0);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (ft_error("failed to initialize mutex"), 0);
	return (1);
}
