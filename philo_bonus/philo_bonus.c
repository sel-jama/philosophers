/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 06:49:14 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/22 13:42:56 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*alive_or_dead(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->last_meal_sem);
		if (ft_ms_cur_time() - philo->data->time_start
			- philo->last_meal_time > philo->data->time_to_die)
		{
			philo->data->death = 1;
			ft_print_case(philo->philo_num, philo->data, "died", 1);
			sem_post(philo->data->last_meal_sem);
			exit(3);
		}
		sem_post(philo->data->last_meal_sem);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philo;
	int		i;
	int		status;

	
	sem_unlink("fork_sem");
	sem_unlink("print_sem");
	sem_unlink("last_meal_sem");
		// sem_unlink("/last_meal_sem");
	i = 0;
	if (!ft_check_args(ac, av))
		return (1);
	philo.data = &data;
	data.time_start = ft_ms_cur_time();
	init_philo_data(&philo, &data, av, ac);
	if (!open_forks(&data))
			return (2);
	data.pid = malloc(sizeof(pid_t) * data.num_of_philos);
	start_philos(data, philo);
	while (1)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
			break ;
	}
	i = 0;
	while (i < data.num_of_philos)
	{
		kill(data.pid[i], SIGKILL);
		i++;
	}
	sem_close(data.fork_sem);
	sem_close(data.print_sem);
	sem_close(data.last_meal_sem);
	return (EXIT_SUCCESS);
}
