/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 06:49:14 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/19 10:24:59 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_ms_cur_time() - philo->data->time_start
			- philo->last_meal_time > philo->data->time_to_die)
		{
			philo->data->death = 1;
			ft_print_case(philo[i].philo_num, &philo->data, "died", 1);
			exit(0);
		}
	}
}
	
}

void	clean_up_memory(t_philo *philo, t_data *data)
{
	free(philo);
	free(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	int		i;

	if (ac == 5 || ac == 6)
	{
		sem_unlink("forks_sem");
		sem_unlink("print_sem");
		i = 0;
		data.time_start = ft_ms_cur_time();
		init_philo_data(data, av, ac);
		init_data(philo, &data);
		if (!open_forks(data))
			return (0);
		data->id = malloc(sizeof(pid_t) * data.num_of_philos);
		start_philo(data);
		//waitpid
		i = 0;
		while(i < data.num_of_philos)
		{
			sem_close(data.forks);
			i++;
		}
		sem_close(data.print_sem);
		sem_unlink("fork_sem");
		sem_unlink("print_sem");
		clean_up_memory(philo, data);
	}
	else
		printf("Invalid number of arguments\n");
}
