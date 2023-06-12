/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 07:19:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/12 20:25:41 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    if (ac == 5)
    {
        t_data      *data;
        t_philo     *philo;
        int         i;
        i = 0;   
        data = malloc(sizeof(t_data));
        init_philo_data(data, av);
        // printf("num of philos %d\n", data->num_of_philos);
        philo = malloc(sizeof(t_philo) * data->num_of_philos);
        init_forks(data);
        init_data(philo, data->num_of_philos);
        while (i < data->num_of_philos)
        {
            printf("hello\n");
            printf("here %d\n", philo[i].philo_num);
            pthread_create(&philo[i].id, NULL, philosopher_routine, &philo[i]);
            usleep(50);
            i++;
        }
        while(1)
        {
            i = 0;
            while(i < philo->data->num_of_philos)
            {
                if (ft_ms_cur_time() - philo[i].last_meal_time > data->time_to_die)
                {
                    philo->data->death = 1;
                    ft_print_case(philo[i].philo_num, &philo->data, "died", 1);
                    break;
                }
                i++;
            }
        }
        i = 0;
        while(i < philo->data->num_of_philos)
        {
            pthread_mutex_destroy(&data->forks[i]);
            i++;
        }
        pthread_mutex_destroy(&data->print_mutex);
    }
    else
        printf("Invalid number of arguments\n");
}
