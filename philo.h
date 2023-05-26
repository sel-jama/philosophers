/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:35:43 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/26 09:32:43 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
 #include <sys/time.h>

typedef struct s_data
{
    int num_of_philos;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
    struct timeval time_beg;
    pthread_mutex_t *forks;
    pthread_mutex_t *print;
}t_data;

typedef struct s_philo
{
    int philo_num;
    t_data  *data;   
}t_philo;

void    *philosopher_routine(void *philo);

#endif