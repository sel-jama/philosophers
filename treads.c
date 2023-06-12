/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 03:58:37 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/12 20:25:53 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philosopher_routine(void *arg)
{
    t_philo *philo;
    t_data  *data;
    int     philo_id;

    philo = (t_philo*)arg;
    philo_id = philo->philo_num;
    data = philo->data;
    while(1)
    {
        if ( philo_id % 2 == 0)
            usleep(data->time_to_eat);
        pickup_forks(philo_id, philo);
        philo->last_meal_time = ft_ms_cur_time() - data->time_start;
        ft_print_case(philo_id, &data, "is eating", 0);
        usleep(data->time_to_eat);
        putdown_forks(philo);
        ft_print_case(philo_id, &data, "is sleeping", 0);
        usleep(data->time_to_sleep);
        ft_print_case(philo_id, &data, "is thiking", 0);
    }
}
void    pickup_forks(int philo_num, t_philo *philo)
{
    pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
    ft_print_case(philo_num, &philo->data, "has taken a fork", 0);
    pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
    ft_print_case(philo_num, &philo->data, "has taken a fork", 0);
}
void    putdown_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
    pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}

void   ft_print_case(int philo_num, t_data **data, char *s, int death)
{
    long long   case_time;
    pthread_mutex_lock(&(*data)->print_mutex);
    case_time = ft_ms_cur_time() - (*data)->time_start * 1000;
    printf("%lld %d %s\n", case_time, philo_num, s);
    if (death == 0)
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