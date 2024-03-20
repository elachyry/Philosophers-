/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:21:05 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/19 16:39:30 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>


typedef struct s_data t_data;

//fork struct
typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

//philo struct
typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_fork			*first_fork;
	t_fork			*second_fork;
	size_t			number_of_meals;
	int				is_finished;
	int				is_dead;
	int				is_eating;
	pthread_mutex_t	philo_mutex;
	size_t			last_meal_time;
	t_data			*data;
}	t_philo;

//data struct
typedef struct s_data
{
	size_t			number_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nbr_time_must_eat;
	int				is_all_thread_created;
	int				is_someone_died;
	int				running_threads;
	size_t			started_time;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_2;
	pthread_mutex_t	mutex_3;
	pthread_mutex_t	mutex_4;
	pthread_t		monitor;
	t_philo			*philos;
	t_fork			*forks;
}	t_data;

//tools
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strlen(const char *str);
char	*ft_trim(char *str);

//parsing
int		parsing(char **argv);

//init variables
void	init_variables(t_data *data, char **argv);

//free data
int		free_data(t_data *data);

//start program
int		start_program(t_data *data);
int		is_someone_died(t_data *data);

//utils
int		lock_mutex(pthread_mutex_t *mutex, int place);
int		unlock_mutex(pthread_mutex_t *mutex);
int		set_int_mutex(pthread_mutex_t *mutex, int *var, int val);
int		increment_int_mutex(pthread_mutex_t *mutex, int *var, int val);
int		get_int_mutex(pthread_mutex_t *mutex, int *var);
int		set_sizet_mutex(pthread_mutex_t *mutex, size_t *var, size_t val);
size_t	get_sizet_mutex(pthread_mutex_t *mutex, size_t *var);
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
void	philo_taken_fork_printing(t_philo *philo);
void	philo_eating_printing(t_philo *philo);
void	philo_sleeping_printing(t_philo *philo);
void	philo_thinking_printing(t_philo *philo);
void	philo_died_printing(t_philo *philo);
void	philo_eating(t_philo *philo);
void	philo_sleeping(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	*start_observation(void *arg);

#endif