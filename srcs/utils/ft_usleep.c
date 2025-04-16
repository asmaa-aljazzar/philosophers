/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:02:12 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/15 17:34:17 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_usleep (size_t ms)
{
    size_t	start;

	start = ft_current_time();
	while ((ft_current_time() - start) < ms)
		usleep(500);
	return (0);
}

//!❓ Why not just use usleep(ms * 1000)?
//? Because usleep(ms * 1000) is not accurate 
//? for very small timing in multithreaded environments, 