/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_found.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:03:14 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/19 18:51:07 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//? Done
#include "../../../../includes/philo.h"


int death_found(t_philo *philos)
{
    pthread_mutex_lock(philos->dead_lock);
    if (*philos->dead == 1)
    {
        pthread_mutex_unlock(philos->dead_lock);
        return (1);
    }
        pthread_mutex_unlock(philos->dead_lock);
    return (0);
}