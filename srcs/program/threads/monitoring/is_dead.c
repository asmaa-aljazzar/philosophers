/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:48:50 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/14 19:34:55 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/philo.h"

// make philo dead when time_to_die
// also check if philo is currently eating
// checks the current philosopher's time since last meal.
static int philo_dead (t_philo *philos, size_t time_to_die)
{
    t_philo *philo;
    size_t now;

    philo = philos;
    now = ft_current_time();
    pthread_mutex_lock(philo->pasta_lock);
    if (now - philo->last_meal > philo->time_to_die && philo->eating == 0)
        return (pthread_mutex_unlock(philo->pasta_lock), 1);
    pthread_mutex_unlock(philo->pasta_lock);
    return (0);
}

// dead lock is one lock for all philos so we just use philos[0] to lock and unlock it.
// print the die message before change the value of dead.

int is_dead(t_philo *philos)
{
    int i;
    i = 0;
    while (i < philos[0].num_of_philos)
    {
        if (philo_dead (&philos[i], philos[i].time_to_die))// Todo
        {
            print_msg ("die", &philos[i]); // todo
            pthread_mutex_lock (philos[0].dead_lock);
            philos[i].dead = 1;
            pthread_mutex_unlock (philos[0].dead_lock);
            return (1);
        }
    }
    return (0);
}
