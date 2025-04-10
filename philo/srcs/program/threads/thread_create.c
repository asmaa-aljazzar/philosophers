/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:35:46 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/10 12:21:29 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

//TODO:  
// destroy_all()

int    thread_create(t_program *program, pthread_mutex_t *forks)
{
    pthread_t   observer_thread;
    int i;

    if (pthread_create(&observer_thread, NULL, &monitoring, &program->philos) != 0) // if something wrong happened while creating a thread, must destroy all threads to avoid zombies threads.
        destroy_all("\e[31m Thread creation error \e[0m", program, forks);
    i = 0;
    while (i < program->philos[0].num_of_philos)
    {
        if (pthread_create(&program->philos[i].thread, NULL, &philo_routine, &program->philos[i]) != 0) 
            destroy_all("\e[31m Thread creation error \e[0m", program, forks);
        i++;
    }
    if (pthread_join(observer_thread, NULL) != 0)
        destroy_all("\e[31m Thread joining error \e[0m", program, forks);
    i = 0;
    while (i < program->philos[0].num_of_philos)
    {
        if (pthread_join(program->philos[i].thread, NULL) != 0)
            destroy_all("\e[31m Thread joining error \e[0m", program, forks);
        i++;
    }
    return 0;
}
