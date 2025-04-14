/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:47:53 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/13 14:23:43 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void    program_init(t_program *program, t_philo *philos)
{
    // when this is 1, there is a dead philo.
    program->dead_flag = 0;
    // This array with t_philo type, each one of the array member
    // has a properties and will contain all philo needs.
    program->philos = philos;
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);
    pthread_mutex_init(&program->pasta_lock, NULL);
}
