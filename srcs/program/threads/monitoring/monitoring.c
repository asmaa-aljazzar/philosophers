/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:45:42 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/16 16:39:24 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//? Done
#include "../../../../includes/philo.h"

void    *monitoring(void *philo_ptr)
{
   t_philo *philos;
   philos = (t_philo *)philo_ptr;
   while (1)
      if (is_dead(philos) || is_all_eat(philos))
         break;
   return (philo_ptr);
}
