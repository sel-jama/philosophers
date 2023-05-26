/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:36:06 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/26 09:37:41 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philosopher_thread(void *arg) {
    PhilosopherData *data = (PhilosopherData *)arg;
    int philosopher_number = data->philo_number;
    SimulationData *sim_data = data->sim_data;
    int left_fork = (philosopher_number - 1) % sim_data->number_of_philos;
    int right_fork = philosopher_number % sim_data->number_of_philos;

    while (1)
    { 
        if (sim_data->number_of_times_each_philo_must_eat != -1 
            && sim_data->eat_count[philosopher_number - 1] >= sim_data->number_of_times_each_philo_must_eat)
        {
            free(data);
            return NULL;
        }

        pick_forks(philosopher_number, sim_data);
        print_message(philosopher_number, "is eating", sim_data);
        usleep(sim_data->time_to_eat * 1000);
        release_forks(philosopher_number, sim_data);

        print_message(philosopher_number, "is sleeping", sim_data);
        usleep(sim_data->time_to_sleep * 1000);

        print_message(philosopher_number, "is thinking", sim_data);
    }
}

// void pick_forks(int philosopher_number, SimulationData *sim_data) 
// {
//     pthread_mutex_lock(&sim_data->forks[philosopher_number - 1]);
//     print_message(philosopher_number, "has taken a fork", sim_data);
//     pthread_mutex_lock(&sim_data->forks[philosopher_number % sim_data->number_of_philos]);
//     print_message(philosopher_number, "has taken a fork", sim_data);
// }

// void release_forks(int philosopher_number, SimulationData *sim_data) {
//     pthread_mutex_unlock(&sim_data->forks[philosopher_number - 1]);
//     pthread_mutex_unlock(&sim_data->forks[philosopher_number % sim_data->number_of_philos]);
// }

// void print_message(int philosopher_number, char *message, SimulationData *sim_data) {
//     pthread_mutex_lock(sim_data->print_mutex);
//     long long timestamp = get_time_in_ms() - sim_data->start_time.tv_sec * 1000;
//     printf("%lld %d %s\n", timestamp, philosopher_number, message);
//     fflush(stdout);
//     pthread_mutex_unlock(sim_data->print_mutex);
// }

// long long get_time_in_ms() {
//     struct timeval current_time;
//     gettimeofday(&current_time, NULL);
//     return current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
// }
