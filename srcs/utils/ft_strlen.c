/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:38:58 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/14 19:40:36 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str)
	{
		len++;
	}
	printf("len = %d", len);
	return (len);
}
