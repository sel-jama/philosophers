/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 07:19:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/04 13:00:53 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    if (ac == 5)
    {
        t_data      data;
        t_philo     *philo_data;
        pthread_t   philos[4];
        int         i;
        init_philo_data(&data, av);
        init_forks(&data);
        i =0;   
        philo_data = malloc(sizeof(t_philo));
        philo_data->data = &data;
        while (i < data.num_of_philos)
        {
            philo_data->philo_num = i + 1;
            pthread_create(&philos[i], NULL, philosopher_routine, philo_data);
            // if (ft_ms_cur_time() - philo_data->data->last_meal_time > philo_data->data->time_to_die * 1000)
            // {
            //     printf("heere %lld ",philo_data->data->last_meal_time);
            //     printf("philosopher %d has died\n", philo_data->philo_num);
            //     exit(1);
            // }
            i++;
        }
        i = 0;
        while (i < data.num_of_philos)
        {
            pthread_join(philos[i], NULL);
            i++;
        }
        i = 0;
        while(i < data.num_of_philos)
        {
            pthread_mutex_destroy(&data.forks[i]);
            i++;
        }
        pthread_mutex_destroy(&data.print_mutex);
    }
    else
        printf("Invalid number of arguments\n");
}
