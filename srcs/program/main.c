/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:07:11 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/23 13:38:33 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

//? argv[1] = num_of_philo
//? argv[2] = time_to_die
//? argv[3] = time_to_eat
//? argv[4] = time_to_sleep
//? argv[5] = [ num of times each philo must eat ]

int	main(int argc, char **argv)
{
	pthread_mutex_t	forks[PHILO_MAX];
	t_program		program;
	t_philo			philos[PHILO_MAX];

	if (argc == 5 || argc == 6)
	{
		if (check_input1(argv) == 0)
		{
			program_init (&program, philos);
			forks_init (forks, ft_atoi(argv[1]));
			philos_init (philos, &program, forks, argv);
			thread_create (&program, forks);
			destroy_all(NULL, &program, forks);
		}
	}
	else
		write_error ("\e[31mShould be 4 or 5 arguments\e[0m");
	return (0);
}
