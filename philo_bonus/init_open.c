/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 06:51:10 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/19 10:10:28 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_data(t_philo philo, t_data *data)
{
	philo.philo_num = i + 1;
	philo.data = data;
	philo.last_meal_time = 0;
}

void	init_philo_data(t_data data, char **av, int ac)
{
	data.num_of_philos = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	data.death = 0;
	if (ac == 6)
		data.meals = ft_atoi(av[5]);
}

int	open_forks(t_data data)
{
	if ((data.fork_sem = sem_open("/forks", O_CREAT, 0644, data.num_of_philos)))
			return (ft_error("failed to open semaphore"), 0);
	if ((data->print_sem = sem_open("/print_sem", O_CREAT, 0644, 1)))
		return (ft_error("failed to open semaphore"), 0);
	return (1);
}
void	start_philo(t_data data)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < data.num_of_philos)
	{
		philo.philo_num = i + 1;
		data.pid[i] = fork();
		if (data.pid[i] == 0)
			routine(philo);
		else 
			exit(1);
		i++;
	}
}
 