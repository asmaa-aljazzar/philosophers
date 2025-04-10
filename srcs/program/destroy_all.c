/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:01:26 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/10 12:15:45 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    destroy_all (char *str, t_program *program, pthread_mutex_t *forks)
{
    int i;
    i = 0;
    while (i < program->philos[0].num_of_philos)
    {
        pthread_mutex_destroy (&forks[i]);
        i++;
    }
    if (program)
    {
    }
    write_error (str);
}