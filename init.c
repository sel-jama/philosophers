/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:56:32 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/26 03:19:17 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_philo_data(t_philo *philo, char **av)
{
    philo->data->num_of_philos = atoi(av[1]);
    philo->data->time_to_die = atoi(av[2]);
    philo->data->time_to_eat = atoi(av[3]);
    philo->data->time_to_sleep = atoi(av[4]);
    gettimeofday(&philo->data->time_beg, NULL);
}

void    init_forks(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->data->num_of_philos)
    {
        if (pthread_mutex_init(&philo->data->forks[i], NULL) != 0)
            error_exit("failed to initialize mutex", 1);
        i++;
    }
    if (pthread_mutex_init(&philo->data->print, NULL) != 0)
        error_exit("failed to initialize mutex", 1);
} 