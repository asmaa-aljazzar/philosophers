/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:00:53 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/03 07:48:15 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_atoi(char *str)
{
	unsigned long long	nb;
	int					sign;
	int					i;

	nb = 0;
	sign = 1;
	i = 0;
    if (str)
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' 
            || str[i] == '\f' || str[i] == '\r')
            i++;
        if (str[i] == '-')
            sign = -1;
        if (str[i] == '-' || str[i] == '+')
            i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            nb = nb * 10 + (str[i] - '0');
            i++;
        }
    }
	return (sign * nb);
}