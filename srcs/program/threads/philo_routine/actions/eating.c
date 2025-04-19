/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:21:13 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/19 20:30:45 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/philo.h"
//? Done

//? after taking the right fork if the num of philo is 1
//! this is mean there is no left fork and the philo will 
//! die from starving after time_to_die pass.

void eating(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    print_msg("has taken a fork", philo, philo->id);
    if (philo->num_of_philos == 1)
    {
        ft_usleep (philo->time_to_die);
        pthread_mutex_unlock (philo->right_fork);
        return ;
    }
    pthread_mutex_lock (philo->left_fork);
    print_msg("has taken a fork", philo, philo->id);
    philo->eating = 1;
    print_msg ("is eating", philo, philo->id);
    pthread_mutex_lock (philo->pasta_lock);
    philo->last_meal = ft_current_time();
    philo->meals_done++;
    pthread_mutex_unlock (philo->pasta_lock);
    ft_usleep (philo->time_to_eat);
    philo->eating = 0;
    pthread_mutex_unlock (philo->left_fork);
    pthread_mutex_unlock (philo->right_fork);
    
}
