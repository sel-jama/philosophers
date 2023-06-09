/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 07:19:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/06/04 13:00:53 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
    philo->data->is_dead = 0;
	while (1)
	{
		if (philo->next_meal < ft_get_time())
		{
			philo->data->is_dead = 1;
			pthread_mutex_lock(philo->eat);
			print_message()
			pthread_mutex_unlock(philo->data->stop);
			break ;
		}
	}
	return (NULL);
}*/

int main(int ac, char **av)
{
    if (ac == 5)
    {
        t_data      *data;
        t_philo     *philo;
        int         i;
        i =0;   
        data = malloc(sizeof(t_data));
        init_philo_data(data, av);
        philo = malloc(sizeof(t_philo) * data->num_of_philos);
        init_forks(data);
        init_data(data);
        while (i < data->num_of_philos)
        {
            pthread_create(&(data->philo[i]).id, NULL, philosopher_routine, &data->philo[i])
            usleep(50);
            i++;
        }
        while(1)
        {
            i = 0;
            while(i < philo->data->num_of_philos)
            {
                if (ft_ms_cur_time() - philo->last_meal_time > data->time_to_die)
                {
                    ft_print_case(philo->philo_num, &philo->data, "died", 1);
                    return (1);
                }
                i++;
            }
        }
        i = 0;
        while(i < data->num_of_philos)
        {
            pthread_mutex_destroy(&data->forks[i]);
            i++;
        }
        pthread_mutex_destroy(&data->print_mutex);
    }
    else
        printf("Invalid number of arguments\n");
}
