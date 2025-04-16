/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:01:26 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/16 17:18:05 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    destroy_all(char *str, t_program *program, pthread_mutex_t *forks)
{
    int i;
    i = 0;
    write_error (str);
    pthread_mutex_destroy (&program->write_lock);   
    pthread_mutex_destroy (&program->pasta_lock);   
    pthread_mutex_destroy (&program->dead_lock);   
    while (i < program->philos[0].num_of_philos)
    {
        pthread_mutex_destroy (&forks[i]);
        i++;
    }

}
