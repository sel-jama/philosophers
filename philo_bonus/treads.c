/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 03:58:37 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/17 03:22:29 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		philo_id;

	philo = (t_philo *)arg;
	philo_id = philo->philo_num;
	data = philo->data;
	if (philo_id % 2 == 0)
		ft_usleep(data->time_to_eat);
	while (1)
	{
		pickup_forks(philo_id, philo);
		set_wait(&philo->last_meal_mutex);
		philo->last_meal_time = ft_ms_cur_time() - data->time_start;
		sem_post(&philo->last_meal_mutex);
		ft_print_case(philo_id, &data, "is eating", 0);
		ft_usleep(data->time_to_eat);
		putdown_forks(philo);
		ft_print_case(philo_id, &data, "is sleeping", 0);
		ft_usleep(data->time_to_sleep);
		ft_print_case(philo_id, &data, "is thiking", 0);
	}
}

void	pickup_forks(int philo_num, t_philo *philo)
{
	if (!sem_wait(&philo->data->forks[philo->l_fork]))
		ft_print_case(philo_num, &philo->data, "has taken a fork", 0);
	if (!sem_wait(&philo->data->forks[philo->r_fork]))
		ft_print_case(philo_num, &philo->data, "has taken a fork", 0);
}

void	putdown_forks(t_philo *philo)
{
	sem_post(&philo->data->forks[philo->l_fork]);
	sem_post(&philo->data->forks[philo->r_fork]);
}

void	ft_print_case(int philo_num, t_data **data, char *s, int death)
{
	long long	case_time;

	sem_wait(&(*data)->print_mutex);
	case_time = ft_ms_cur_time() - (*data)->time_start;
	printf("%lldms %d %s\n", case_time, philo_num, s);
	if (death == 0)
		sem_post(&(*data)->print_mutex);
}

long long	ft_ms_cur_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}
