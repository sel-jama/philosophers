/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 04:10:31 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/26 03:26:27 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int main(int argc, char *argv[]) {
//     t_philo philo;
//     void *forks;
//     philo.data.forks = forks;
//     sim_data.print_mutex = &print_mutex;
//     sim_data.eat_count = eat_count;
//     i = 0;
//     while(i < sim_data.number_of_philos)
//     {
//         PhilosopherData *philosopher_data = malloc(sizeof(PhilosopherData));
//         philosopher_data->philo_number = i + 1;
//         philosopher_data->sim_data = &sim_data;
//         pthread_create(&philosophers[i], NULL, philosopher_thread, philosopher_data);
//         i++;
//     }
//     i = 0;
//     while(i < sim_data.number_of_philos)
//     {
//         pthread_join(philosophers[i], NULL);
//         i++;
//     }
//     i = 0;
//     while(i < sim_data.number_of_philos)
//     {
//         pthread_mutex_destroy(&forks[i]);
//         i++;
//     }
//     pthread_mutex_destroy(&print_mutex);
//     return 0;
// }





















//  if (argc < 5 || argc > 6) {
//         printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
//         return 1;
//     }

//     // SimulationData sim_data;
//     pthread_mutex_t forks[sim_data.number_of_philos];
//     pthread_mutex_t print_mutex;
//     int eat_count[sim_data.number_of_philos];
//     int i;
//     pthread_t philosophers[sim_data.number_of_philos];
    
//     sim_data.number_of_philos = atoi(argv[1]);
//     sim_data.time_to_die = atoi(argv[2]);
//     sim_data.time_to_eat = atoi(argv[3]);
//     sim_data.time_to_sleep = atoi(argv[4]);
//     if (argc == 6)
//         sim_data.number_of_times_each_philo_must_eat = atoi(argv[5]);
//     else
//         sim_data.number_of_times_each_philo_must_eat = -1;
//     gettimeofday(&sim_data.start_time, NULL);
//     i = 0;
//     while(i < sim_data.number_of_philos) {
//         pthread_mutex_init(&forks[i], NULL);
//         eat_count[i] = 0;
//         i++;
//     }
//     pthread_mutex_init(&print_mutex, NULL);