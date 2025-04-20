/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:57:21 by aaljazza          #+#    #+#             */
/*   Updated: 2025/04/20 05:34:57 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//?<<<<<<<<[ Libraries ]>>>>>>>>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

//?<<<<<<<<[ Defines ]>>>>>>>>
# define PHILO_MAX 200

//?<<<<<<<<[ Structures ]>>>>>>>>

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int eating;
    int meals_done;
    int num_of_philos;
    int num_times_to_eat;
    size_t  last_meal; // size_t because it store the timestamps "raquire an unsigned type and enough capacity"
    size_t  start_time;
    size_t  time_to_eat;
    size_t  time_to_die;
    size_t  time_to_sleep;
    int *dead;
    pthread_mutex_t  *dead_lock;
    pthread_mutex_t  *left_fork;
    pthread_mutex_t  *right_fork;
    pthread_mutex_t  *pasta_lock; // one philo eating from the pasta
    pthread_mutex_t  *write_lock; // ensuring that one thread is printing at the time
}	t_philo;

typedef struct s_program
{
    int dead_flag; 
    t_philo *philos;
    pthread_mutex_t  write_lock;
    pthread_mutex_t  dead_lock;
    pthread_mutex_t  pasta_lock; 

}   t_program;


//?<<<<<<<<[ Functions Definition ]>>>>>>>>

// *** convert the string into and integer ***
//- return the number when succes.
//- return nothing if the input containing a non-numeric character.
int ft_atoi(char *str);

// calculate the length of a string and return it.
int ft_strlen(char *str);

// *** check if input is correct *** 
//- return 0 when success.
//- return non-zero value in case of error
int check_input(char **argv);

// *** print a string on the standard error ***
int    write_error(char *str);

// *** initialize the program structure using input from the user ***
void    program_init(t_program *program, t_philo *philos);

// *** initialize forks with the same numbers of philos ***
void forks_init(pthread_mutex_t *forks, int num_of_forks);

// *** initialize the philos structure ***
void    philos_init (t_philo *philo, t_program *program, pthread_mutex_t *forks, char **argv);

// *** continue initialize the philo structure using the user input ***
void input_init (t_philo *philo,char **argv);

// *** destroy all created mutex in program structure and forks array ***
void    destroy_all (char *str, t_program *program, pthread_mutex_t *forks);

// *** create all threads with routine function ***
int  thread_create(t_program *program, pthread_mutex_t *forks);

// *** routine function for philosophers threads ***
void    *philo_routine (void *philo_ptr);

// *** routine function for observer thread ***
//  if the philo dead or all philos eats the num of meanl.
//  - return a pointer to the philo.
void    *monitoring (void *philos);

// *** get the current time from a device ***
size_t    ft_current_time();

// *** eating action ***
void eating(t_philo *philo);

// *** sleeping action ***
void sleeping(t_philo *philo);

// *** thinking action ***
void thinking(t_philo *philo);

// *** check if one of philos is dead ***
// - return 1 when death happened.
int is_dead(t_philo *philos);

// *** check all philos at least ate the num of meals ***
// - return 1 when all eat the num of meals.
int is_all_eat(t_philo *philos);

// *** print a messages to descripe the simulation ***
void    print_msg(char *str, t_philo *philo, int philo_id);

//This function tries to pause execution for a certain number of milliseconds, 
//but in a more accurate and controlled way than using usleep() alone.
int ft_usleep (size_t ms, t_philo *philo);

//- if found a death it will return 1.
//- else it will return 0.
int death_found(t_philo *philos);

#endif
