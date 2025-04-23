/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:22:01 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/23 14:26:34 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/philo.h"

void	sleeping(t_philo *philo)
{
	print_msg ("is sleeping", philo, philo->id);
	ft_usleep (philo->time_to_sleep, philo);
}
