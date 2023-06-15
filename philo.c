/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 07:19:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/15 21:52:14 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philo, t_data *data)
{
	int	i;

	while (!data->death)
	{
		i = 0;
		while (i < data->num_of_philos)
		{
			pthread_mutex_lock(&philo[i].last_meal_mutex);
			if (ft_ms_cur_time() - data->time_start
				- philo[i].last_meal_time > data->time_to_die)
			{
				data->death = 1;
				ft_print_case(philo[i].philo_num, &data, "died", 1);
				pthread_mutex_unlock(&philo[i].last_meal_mutex);
				break ;
			}
			pthread_mutex_unlock(&philo[i].last_meal_mutex);
			i++;
		}
	}
}

void	join_or_destroy(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (data->death)
			break ;
		pthread_join(philo[i].id, NULL);
		i++;
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&philo[i].last_meal_mutex);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	if (ac == 0)
	{
		i = 0;
		data = malloc(sizeof(t_data));
		data->time_start = ft_ms_cur_time();
		init_philo_data(data, av);
		philo = malloc(sizeof(t_philo) * data->num_of_philos);
		init_data(philo, data, data->num_of_philos);
		init_forks(data);
		while (i < data->num_of_philos)
		{
			pthread_create(&philo[i].id, NULL, philosopher_routine, &philo[i]);
			ft_usleep(10);
			i++;
		}
		check_death(philo, data);
		join_or_destroy(data, philo);
	}
	else
		printf("Invalid number of arguments\n");
}
