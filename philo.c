/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 07:19:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/26 03:58:16 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_philo philo;
    pthread_t philos[philo.data->num_of_philos];
    int     i;
    if (ac != 5)
        printf("Invalid number of arguments\n");
    init_philo_data(&philo, av);
    init_forks(&philo);
    i =0;
    while (i < philo.data->num_of_philos)
    {
        philo.philo_rank = i + 1;
        pthread_create(&philos[i], NULL, philosopher_cycle, &philo);
        i++;
    }
    i = 0;
    while (i < philo.data->num_of_philos)
    {
        pthread_join(philos[i], NULL);
        i++;
    }
    return (0);
}