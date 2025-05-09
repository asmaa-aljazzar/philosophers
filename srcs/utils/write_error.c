/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:44:56 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/23 06:30:30 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	write_error(char *str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			write (2, &str[i], 1);
			i++;
		}
		write (2, "\n", 1);
	}
}
