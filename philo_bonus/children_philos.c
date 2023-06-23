/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 06:48:18 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/23 12:18:32 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(t_philo philo)
{
	int		philo_id;

	philo_id = philo.philo_num;
	if (philo_id % 2 == 0)
		ft_usleep(philo.data->time_to_eat);
	pthread_create(&philo.id, NULL, alive_or_dead, &philo);
	while (1)
	{
		if (philo.data->ac == 6 && philo.data->must_eat <= 0)
			exit(10);
		pickup_forks(philo_id, philo);
		// philo.last_meal_time = ft_ms_cur_time() - philo.data->time_start;
		ft_print_case(philo_id, philo.data, "is eating", 0);
		sem_wait(philo.data->last_meal_sem);
		gettimeofday(&philo.data->last_meal_s, NULL);
		sem_post(philo.data->last_meal_sem);
		if(philo.data->must_eat > 0)
		{
			// sem_wait(philo.data->eaten_meals_sem);
			philo.data->must_eat -= 1;
			// sem_post(philo.data->eaten_meals_sem);
		}
		ft_usleep(philo.data->time_to_eat);
		putdown_forks(philo);
		ft_print_case(philo_id, philo.data, "is sleeping", 0);
		ft_usleep(philo.data->time_to_sleep);
		ft_print_case(philo_id, philo.data, "is thiking", 0);
	}
}

void	pickup_forks(int philo_num, t_philo philo)
{
	if (!sem_wait(philo.data->fork_sem))
		ft_print_case(philo_num, philo.data, "has taken a fork", 0);
	if (!sem_wait(philo.data->fork_sem))
		ft_print_case(philo_num, philo.data, "has taken a fork", 0);
}

void	putdown_forks(t_philo philo)
{
	sem_post(philo.data->fork_sem);
	sem_post(philo.data->fork_sem);
}

void	ft_print_case(int philo_num, t_data *data, char *s, int death)
{
	long long	case_time;

	sem_wait(data->print_sem);
	case_time = ft_ms_cur_time() - data->time_start;
	printf("%lldms %d %s\n", case_time, philo_num, s);
	if (death == 0)
		sem_post(data->print_sem);
}

long long	ft_ms_cur_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}
