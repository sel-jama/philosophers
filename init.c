/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:56:32 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/12 19:40:24 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_data(t_philo *philo, int num_of_philos)
{
    int i = 0;
    
    t_data data;

    // data->philo = &philo;
    while(i < num_of_philos)
    {
        philo[i].philo_num = i + 1;
        philo[i].data = &data;
        philo[i].last_meal_time = 0;
        philo[i].r_fork = (philo[i].philo_num) % num_of_philos;
        philo[i].l_fork = (philo[i].philo_num - 1) % num_of_philos;
        i++;
    }
}

void    init_philo_data(t_data *data, char **av)
{
    // if ac == 5 ac == 6
    data->num_of_philos = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->death = 0;
    // if ac == 6
    //     data meals == ft atoi av 5
    gettimeofday(&data->time_ref, NULL);
    data->time_start = data->time_ref.tv_sec * 1000 + data->time_ref.tv_usec / 1000;
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

// void init_fork_state(t_data *data)
// {
//     int fork_state[data->num_of_philos];
//     int i;
    
//     data->fork_position = fork_state;
//     i = 0;
//     while (i < data->num_of_philos)
//     {
//         data->fork_position[i] = F_AVAILABLE;
//         i++; 
//     }
// }