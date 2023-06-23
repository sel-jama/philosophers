/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 06:51:10 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/23 18:56:42 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_philo_data(t_philo *philo, t_data *data, char **av, int ac)
{
	data->num_of_philos = ft_atoll(av[1]);
	data->time_to_die = ft_atoll(av[2]);
	data->time_to_eat = ft_atoll(av[3]);
	data->time_to_sleep = ft_atoll(av[4]);
	philo->last_meal_time = 0;
	data->death = 0;
	data->ac = ac;
	if (ac == 6)
		data->must_eat = ft_atoll(av[5]);
	else
		data->must_eat = 0;
}

int	open_forks(t_data *data)
{
	data->fork_sem = sem_open("fork_sem", O_CREAT, 0644, data->num_of_philos);
	if (data->fork_sem == SEM_FAILED)
		return (ft_error("failed to open fork semaphore"), 0);
	data->print_sem = sem_open("print_sem", O_CREAT, 0644, 1);
	if (data->print_sem == SEM_FAILED)
		return (ft_error("failed to open print semaphore"), 0);
	data->last_meal_sem = sem_open("last_meal_sem", O_CREAT, 0644, 1);
	if (data->print_sem == SEM_FAILED)
		return (ft_error("failed to open last_meal semaphore"), 0);
	if (data->ac == 6)
	{
		data->eaten_meals_sem = sem_open("eaten_meals_sem", O_CREAT, 0644, 1);
		if (data->eaten_meals_sem == SEM_FAILED)
			ft_error("failed to open eaten_meals semaphore");
	}
	return (1);
}

void	start_philos(t_data data, t_philo philo)
{
	int		i;

	i = 0;
	while (i < data.num_of_philos)
	{
		philo.philo_num = i + 1;
		data.pid[i] = fork();
		if (data.pid[i] == 0)
			routine(philo);
		i++;
	}
}
