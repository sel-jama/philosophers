/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 03:09:17 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/24 07:13:49 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHIL_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_NAME_LENGTH 10

typedef struct {
    int number_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philo_must_eat;
    pthread_mutex_t *forks;
    pthread_mutex_t *print_mutex;
    int *eat_count;
    struct timeval start_time;
} SimulationData;

typedef struct {
    int philo_number;
    SimulationData *sim_data;
} PhilosopherData;


void *philosopher_thread(void *arg);
void pick_forks(int philoso_number, SimulationData *sim_data);
void release_forks(int philosopher_number, SimulationData *sim_data);
void print_message(int philosopher_number, char *message, SimulationData *sim_data);
long long get_time_in_ms();

#endif
