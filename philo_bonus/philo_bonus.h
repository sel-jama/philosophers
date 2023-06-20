/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 06:49:42 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/20 06:51:28 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>  
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				meals;
	int				death;
	long long		time_start;
	pid_t			*pid;
	sem_t	*fork_sem;
	sem_t	*print_sem;
}t_data;

typedef struct s_philo
{
	int				philo_num;
	pthread_t		id;
	long long		last_meal_time;
	t_data			*data;
}t_philo;

void		init_philo_data(t_philo *philo, t_data *data, char **av, int ac);
void		start_philos(t_data data);
void		routine(t_philo philo);
int			open_forks(t_data *data);
void		pickup_forks(int philo_num, t_philo philo);
void		putdown_forks(t_philo philo);
void		ft_print_case(int philo_num, t_data *data, char *s, int death);
void		ft_error(char *msg);
int			ft_atoi(const char *str);
long long	ft_ms_cur_time(void);
void		ft_usleep(long long sleep_dur);
int			ft_strlen(const char *s);
void		*alive_or_dead(void *arg);
void		clean_up_memory(t_philo *philo, t_data *data);

#endif
