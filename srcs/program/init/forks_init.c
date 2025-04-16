/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:05:41 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/16 16:32:37 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//?Done

#include "../../../includes/philo.h"

// No check: if (fork) because we allocate it in main.
void forks_init(pthread_mutex_t *forks, int num_of_forks)
{
    int i;
    i = 0;
    while (i < num_of_forks)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}
