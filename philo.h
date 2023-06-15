/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:35:43 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/15 22:28:09 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
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
	int				*fork_position;
	int				death;
	long long		time_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}t_data;

typedef struct s_philo
{
	int				philo_num;
	pthread_t		id;
	int				l_fork;
	int				r_fork;
	long long		last_meal_time;
	pthread_mutex_t	last_meal_mutex;
	t_data			*data;
}t_philo;

void		init_data(t_philo *philo, t_data *data, int num_of_philos);
void		init_philo_data(t_data *data, char **av);
void		init_forks(t_data *data);
void		*philosopher_routine(void *philo);
void		pickup_forks(int philo_num, t_philo *philo);
void		putdown_forks(t_philo *philo);
void		ft_print_case(int philo_num, t_data **data, char *s, int death);
void		ft_error_exit(char *msg, int n);
int			ft_atoi(const char *str);
long long	ft_ms_cur_time(void);
void		ft_usleep(long long sleep_dur);
int			ft_strlen(const char *s);
void		check_death(t_philo *philo, t_data *data);
void		join_or_destroy(t_data *data, t_philo *philo);

#endif
