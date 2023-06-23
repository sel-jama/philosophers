/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 07:19:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/23 20:39:39 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eaten_meals_check(t_philo *philo)
{
	if (philo->data->ac == 6)
	{
		pthread_mutex_lock(&philo->data->eaten_meals_mutex);
		philo->meals_count -= 1;
		if (philo->meals_count == 0)
		{
			philo->data->eaten_meals += 1;
			pthread_mutex_unlock(&philo->data->eaten_meals_mutex);
		}
		pthread_mutex_unlock(&philo->data->eaten_meals_mutex);
	}
}

void	check_death(t_philo *philo, t_data *data)
{
	int	i;

	while (1)
	{
		if (data->ac == 6)
		{
			pthread_mutex_lock(&data->eaten_meals_mutex);
			if (data->eaten_meals == data->num_of_philos)
				return ;
			pthread_mutex_unlock(&data->eaten_meals_mutex);
		}
		i = -1;
		while (++i < data->num_of_philos)
		{
			pthread_mutex_lock(&data->last_meal_mutex);
			if (ft_ms_cur_time() - data->time_start
				- philo[i].last_meal_time >= data->time_to_die)
			{
				data->death = 1;
				ft_print_case(philo[i].philo_num, &data, "died", 1);
				return ;
			}
			pthread_mutex_unlock(&data->last_meal_mutex);
		}
	}	
}

void	join_or_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->last_meal_mutex);
	if (data->ac == 6)
		pthread_mutex_destroy(&data->eaten_meals_mutex);
}

void	clean_up_memory(t_philo *philo, t_data *data)
{
	free(philo);
	free(data);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	i = 0;
	if (!ft_check_args(ac, av))
		return (1);
	data = malloc(sizeof(t_data));
	data->time_start = ft_ms_cur_time();
	if (!init_philo_data(data, av, ac))
		return (0);
	philo = malloc(sizeof(t_philo) * data->num_of_philos);
	init_data(philo, data, data->num_of_philos);
	if (!init_forks(data))
		return (0);
	while (i < data->num_of_philos)
	{
		pthread_create(&philo[i].id, NULL, philosopher_routine, &philo[i]);
		i++;
	}
	check_death(philo, data);
	join_or_destroy(data);
	clean_up_memory(philo, data);
}
