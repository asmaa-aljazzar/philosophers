/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:02:12 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/20 05:51:13 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// in case of 2 philo with short time to die and large time to eat/sleep
// we should check for any die before sleep

int	ft_usleep (size_t ms, t_philo *philo)
{
    size_t	start;

	start = ft_current_time();
	while (!death_found(philo) && (ft_current_time() - start) < ms)
		usleep(500);
	return (0);
}

//!❓ Why not just use usleep(ms * 1000)?
//? Because usleep(ms * 1000) is not accurate 
//? for very small timing in multithreaded environments, 