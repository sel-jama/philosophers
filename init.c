/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:56:32 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/31 06:57:43 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_philo_data(t_data *data, char **av)
{
    data->num_of_philos = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->last_meal_time = 0;
    gettimeofday(&data->time_ref, NULL);
}

void    init_forks(t_data *data)
{
    int i;
    pthread_mutex_t forks[data->num_of_philos];

    i = 0;
    data->forks = forks;
    while (i < data->num_of_philos)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
            ft_error_exit("failed to initialize mutex", 1);
        i++;
    }
    if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
        ft_error_exit("failed to initialize mutex", 1);
} 