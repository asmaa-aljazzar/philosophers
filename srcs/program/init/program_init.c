/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:47:53 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/23 13:45:20 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

// This array with t_philo type, each one of the array member
// has a properties and will contain all philo needs.

void	program_init(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init (&program->write_lock, NULL);
	pthread_mutex_init (&program->dead_lock, NULL);
	pthread_mutex_init (&program->pasta_lock, NULL);
}
