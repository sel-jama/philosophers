/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 03:58:37 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/31 06:54:07 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philosopher_routine(void *arg)
{
    t_philo *philo;
    t_data  *data;
    int     philo_id;
    int     l_fork;
    int     r_fork;

    philo = (t_philo*)arg;
    data = philo->data;
    philo_id = philo->philo_num;
    l_fork = (philo_id - 1) % data->num_of_philos;
    r_fork = (philo_id) % data->num_of_philos;
    while(1)
    {
            pickup_forks(philo_id, &data);
            data->last_meal_time = ft_ms_cur_time() - ft_time_in_ms(&(data->time_ref));
            ft_print_case(philo_id, &data, "is eating");
            usleep(data->time_to_eat);
            putdown_forks(philo_id, &data);
            ft_print_case(philo_id, &data, "is sleeping");
            usleep(data->time_to_sleep);
            ft_print_case(philo_id, &data, "is thiking");
    }
}
void    pickup_forks(int philo_num, t_data **data)
{
    pthread_mutex_lock(&(*data)->forks[philo_num - 1]);
    ft_print_case(philo_num, data, "has taken a fork");
    pthread_mutex_lock(&(*data)->forks[philo_num % (*data)->num_of_philos]);
    ft_print_case(philo_num, data, "has taken a fork");
}
void    putdown_forks(int philo_num, t_data **data)
{
    pthread_mutex_unlock(&(*data)->forks[philo_num - 1]);
    pthread_mutex_unlock(&(*data)->forks[philo_num % (*data)->num_of_philos]);
}

void   ft_print_case(int philo_num, t_data **data, char *s)
{
    long long   case_time;
    pthread_mutex_lock(&(*data)->print_mutex);
    case_time = ft_ms_cur_time() - ft_time_in_ms(&((*data)->time_ref));
    printf("%lld %d %s\n", case_time, philo_num, s);
    pthread_mutex_unlock(&(*data)->print_mutex);
}
long long ft_ms_cur_time()
{
    struct timeval cur_time;
    long long case_duration;
    gettimeofday(&cur_time, NULL);
    case_duration = cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000;
    return (case_duration);
}