/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:16:40 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/19 19:17:34 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_msg(char *str, t_philo *philo, int philo_id)
{
	size_t	time;

	pthread_mutex_lock (philo->write_lock);
	time = ft_current_time () - philo->start_time;
	if (!death_found (philo))
		printf ("%zu %d %s\n", time, philo_id, str);
	pthread_mutex_unlock (philo->write_lock);
}
