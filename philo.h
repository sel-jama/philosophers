/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:35:43 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/31 06:29:54 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_data
{
    int num_of_philos;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
    long long last_meal_time;
    struct timeval time_ref;
    // pthread_mutex_t *forks;
    // pthread_mutex_t *print;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;

}t_data;

typedef struct s_philo
{
    int philo_num;
    t_data  *data;   
}t_philo;

void    init_philo_data(t_data *data, char **av);
void    init_forks(t_data *data);
void    *philosopher_routine(void *philo);
void    pickup_forks(int philo_num, t_data **data);
void    putdown_forks(int philo_num, t_data **data);
void    ft_print_case(int philo_num, t_data **data, char *s);
void    ft_error_exit(char *msg, int n);
int     ft_atoi(const char *str);
long long ft_ms_cur_time();
long long	ft_time_in_ms(struct timeval *time);
int  ft_strlen(const char *s);

#endif