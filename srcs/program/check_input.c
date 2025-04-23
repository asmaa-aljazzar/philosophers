/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:05:36 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/23 06:31:25 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	input_content(char *str);

int	check_input1(char **argv)
{
	if (input_content (argv[1]) == 0
		|| ft_atoi (argv[1]) <= 0 || ft_atoi (argv[1]) > PHILO_MAX)
	{
		write_error("\e[31m invalid philos number \e[0m");
		return (1);
	}
	if (input_content (argv[2]) == 0 || ft_atoi (argv[2]) < 60)
	{
		write_error("\e[31m invalid time to die \e[0m");
		return (1);
	}
	if (input_content (argv[3]) == 0 || ft_atoi (argv[3]) < 60)
	{
		write_error("\e[31m invalid time to eat \e[0m");
		return (1);
	}
	check_input2(argv);
	return (0);
}
// if argv[5] exist but < 0

int	check_input2(char **argv)
{
	if (input_content (argv[4]) == 0 || ft_atoi (argv[4]) < 60)
	{
		write_error("\e[31m invalid time to sleep \e[0m");
		return (1);
	}
	if (argv[5] && (input_content (argv[5]) == 0 || ft_atoi (argv[5]) < 0))
	{
		write_error("\e[31m invalid num of times each philo should eat \e[0m");
		return (1);
	}
	return (0);
}

// *** check if the content of the input is only numbers ***
//- return 1 when sucess.
//- return 0 in case of the number contain a non-numeric character
static int	input_content(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] > '9' || str[i] < '0')
				return (0);
			else
				i++;
		}
	}
	return (1);
}
