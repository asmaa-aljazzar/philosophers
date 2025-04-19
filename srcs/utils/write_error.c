/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:44:56 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/19 19:07:43 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
// ?Done
int    write_error(char *str)
{
    if (str)
    {
        int i;
        i = 0;
        while (str[i])
        {
            write (2, &str[i], 1);
            i++;
        }
        write (2, "\n", 1);
    }
    return (1);
}
