/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:49:06 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/16 16:35:06 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//? Done
#include "../../../includes/philo.h"

void    philos_init(t_philo *philo, t_program *program, pthread_mutex_t *forks, char **argv)
{
    int i;

    i = 0;
    while (i < ft_atoi(argv[1]))
    {
        philo[i].id = i + 1;
        philo[i].dead = &program->dead_flag;
        philo[i].eating = 0;
        philo[i].meals_done =0;
        input_init (&philo[i], argv); 
        philo[i].pasta_lock = &program->pasta_lock;
        philo[i].write_lock = &program->write_lock;
        philo[i].dead_lock = &program->dead_lock;
        philo[i].start_time = ft_current_time();
        philo[i].last_meal = ft_current_time();
        philo[i].left_fork = &forks[i];
        if (i == 0)
            philo[i].right_fork = &forks[philo[i].num_of_philos - 1];
        else
            philo[i].right_fork = &forks[i - 1];
        i++;
    }
}

