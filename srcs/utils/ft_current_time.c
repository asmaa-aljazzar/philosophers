/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:04:09 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/06 08:08:19 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/philo.h"

size_t    ft_current_time()
{
    struct timeval time;
    
    if (gettimeofday(&time, NULL) == -1)
        write_error ("\e[31m Error: \e[0m gettimeofday()");
    return ((time.tv_sec * 1000 ) + (time.tv_usec / 1000));
 }