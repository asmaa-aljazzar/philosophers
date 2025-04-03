/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:07:11 by aaljazza          #+#    #+#             */
/*   Updated: 2025/03/29 17:08:39 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


//? argv[1] = num_of_philo
//? argv[2] = time_to_die
//? argv[3] = time_to_eat
//? argv[4] = time_to_sleep
//? argv[5] = [ num of times each philo must eat ]

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (check_input(argv) == 0)
		{
			
		}
		else
		{
			printf ("invalid input\n");
		}
	}
	else
		printf ("should be 4 or 5 arguments\n");
	return 0;
}


