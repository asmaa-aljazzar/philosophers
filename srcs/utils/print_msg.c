/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:16:40 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/14 19:33:59 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int death_found(t_philo *philos)
{
    pthread_mutex_lock(philos->dead_lock);
    if (philos->dead == 1)
        return (pthread_mutex_unlock(philos->dead_lock), 1);
    pthread_mutex_lock(philos->dead_lock);
    return (0);
}

// substract start time to calculate the time from the start of the simulation

void    print_msg(char *str, t_philo *philo)
{
    size_t time;
    time = ft_current_time();
    pthread_mutex_lock(philo->write_lock);
    if (!death_found(philo))
        printf ("%zu %d %s", time, philo->id, str);
    pthread_mutex_unlock(philo->write_lock);
}
