/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 06:49:42 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/22 17:34:22 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>  
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <limits.h>

typedef struct s_data
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_sleep;
	int			time_to_eat;
	int			meals;
	int			death;
	long long	time_start;
	pid_t		*pid;
	sem_t		*fork_sem;
	sem_t		*print_sem;
	sem_t		*last_meal_sem;
	struct timeval last_meal_s;
}t_data;

typedef struct s_philo
{
	int			philo_num;
	pthread_t	id;
	long long	last_meal_time;
	t_data		*data;
}t_philo;

void		init_philo_data(t_philo *philo, t_data *data, char **av, int ac);
void		start_philos(t_data data, t_philo philo);
void		routine(t_philo philo);
int			open_forks(t_data *data);
void		pickup_forks(int philo_num, t_philo philo);
void		putdown_forks(t_philo philo);
void		ft_print_case(int philo_num, t_data *data, char *s, int death);
void		ft_error(char *msg);
long long	ft_atoll(const char *str);
long long	ft_ms_cur_time(void);
void		ft_usleep(long long sleep_dur);
int			ft_strlen(const char *s);
void		*alive_or_dead(void *arg);
int			ft_check_args(int ac, char **av);
int			ft_check_empty(char **av);
int			ft_check_int(char **av);

#endif
