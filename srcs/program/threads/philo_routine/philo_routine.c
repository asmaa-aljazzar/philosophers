/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:44:31 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/16 17:00:16 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//? Done
#include "../../../../includes/philo.h"

// if the num of philo is even we will wait 1 ms.
//? to avoid race condition.

void    *philo_routine (void *philo_ptr)
{
    t_philo *philo;

    philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!death_found(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (philo_ptr);
}

