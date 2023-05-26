/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 03:58:37 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/26 09:41:39 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philosopher_routine(void *arg)
{
    t_philo *philo;
    int     l_fork;
    int     r_fork;

    philo = (t_philo*)arg;
    l_fork = (philo->philo_num - 1) % philo->data->num_of_philos;
    r_fork = (philo->philo_num) % philo->data->num_of_philos;
    while(1)
    {
        
    }
}