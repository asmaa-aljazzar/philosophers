/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:48:50 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/20 06:16:31 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//? Done

#include "../../../../includes/philo.h"

// make philo dead when time_to_die
// also check if philo is currently eating
// checks the current philosopher's time since last meal.
static int philo_dead (t_philo *philos, size_t time_to_die)
{

    pthread_mutex_lock(philos->pasta_lock);
    if (ft_current_time() - philos->last_meal >= time_to_die && philos->eating == 0)
        return (pthread_mutex_unlock(philos->pasta_lock), 1);
    pthread_mutex_unlock(philos->pasta_lock);
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
        if (philo_dead (&philos[i], philos[i].time_to_die))
        {
            print_msg ("die", &philos[i], philos[i].id); // todo
            pthread_mutex_lock (philos[0].dead_lock);
            *philos->dead = 1;
            pthread_mutex_unlock (philos[0].dead_lock);
            return (1);
        }
        i++;
    }
    return (0);
}
