/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:48:50 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/23 14:06:15 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/philo.h"

// add 1 to finish if the current philo eats more or equal to num_times_to_eatn 
// finish is the philo who finish 
// if it is equal num of philos this is mean the sumulation is end.

int	is_all_eat(t_philo *philos)
{
	int	i;
	int	finish;

	i = 0;
	finish = 0;
	if (philos[0].num_times_to_eat == -42)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock (philos[i].pasta_lock);
		if (philos[i].meals_done >= philos[i].num_times_to_eat)
			finish++;
		pthread_mutex_unlock (philos[i].pasta_lock);
		i++;
	}
	if (finish == philos[0].num_of_philos)
	{
		pthread_mutex_lock (philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock (philos[0].dead_lock);
		return (1);
	}
	return (0);
}
