/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:31:58 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/06 15:23:12 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void input_init(t_philo *philo,char **argv)
{
    philo->time_to_die = ft_atoi (argv[2]);
    philo->time_to_eat = ft_atoi (argv[3]);
    philo->time_to_sleep = ft_atoi (argv[4]);
    if (argv[5])
        philo->num_times_to_eat = ft_atoi (argv[5]);
    else
        philo->num_times_to_eat = -42;
}