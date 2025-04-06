/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:05:41 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/03 09:47:10 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philo.h"

void forks_init(pthread_mutex_t *forks, int num_of_forks)
{
    // No check: if (fork) because we allocate it in main.
    int i;
    i = 0;
    while (i < num_of_forks)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}