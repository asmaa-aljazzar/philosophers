/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:05:36 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/01 15:06:23 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int input_content (char *str);

int check_input (char **argv)
{
    if (input_content (argv[1]) == 0 || ft_atoi (argv[1]) <= 0 || ft_atoi (argv[1]) > 200)
        return (1);
    if (input_content (argv[2]) == 0 ||  ft_atoi (argv[2]) <= 0)
        return (2);
    if (input_content (argv[3]) == 0 || ft_atoi (argv[3]) <= 0)
        return (3);
    if (input_content (argv[4]) == 0 || ft_atoi (argv[4]) <= 0)
        return (4);
    if ( argv[5] && (input_content (argv[5]) == 0 || ft_atoi (argv[5]) < 0 )) // if argv[5] exist but < 0
            return (5);
    return (0);
}

// *** check the content of the input ***
//- return 1 when sucess.
//- return 0 in case of the number contain a non-numeric character
static int input_content (char *str)
{
    int i;
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
