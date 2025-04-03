#ifndef PHILO_H
# define PHILO_H

//?<<<<<<<<[ Libraries ]>>>>>>>>
#include <stdio.h>
#include <pthread.h>

//?<<<<<<<<[ Structures ]>>>>>>>>

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int dead;
    int eating;
    int meals_done;
    int num_of_philos;
    int num_times_to_eat;
    size_t  last_meal; // size_t because it store the timestamps "raquire an unsigned type and enough capacity"
    size_t  start_time;
    size_t  time_to_eat;
    size_t  time_to_die;
    size_t  time_to_sleep;
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
    pthread_mutex_t write_lock;
    pthread_mutex_t  *dead_lock;
    pthread_mutex_t  *pasta_lock; 

}   t_program;


//?<<<<<<<<[ Functions Definition ]>>>>>>>>

// *** convert the string into and integer ***
//- return the number when succes.
//- return nothing if the input containing a non-numeric character.
int	ft_atoi(char *str);

// *** check if input is correct *** 
//- return 0 when success.
//- return non-zero value in case of error
int check_input (char **argv);


#endif
