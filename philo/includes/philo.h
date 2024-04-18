/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:21:05 by melachyr          #+#    #+#             */
/*   Updated: 2024/04/18 18:54:45 by melachyr         ###   ########.fr       */
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

typedef struct s_data	t_data;

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
	t_fork			*right_fork;
	t_fork			*left_fork;
	int				number_of_meals;
	int				is_finished;
	pthread_mutex_t	philo_mutex;
	size_t			last_meal_time;
	t_data			*data;
}	t_philo;

//data struct
typedef struct s_data
{
	int				number_of_philo;
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
void	ft_putstr_fd(char *s, int fd);

//parsing
int		parsing(char **argv);

//init variables
int		init_variables(t_data *data, char **argv);

//free data
int		free_data(t_data *data);

//start program
int		start_program(t_data *data);
void	*philos_routine(void *arg);
void	*one_philo_routine(void *arg);

//threads utils
int		create_philos_threads(t_data *data);
int		create_observation_thread(t_data *data);
int		join_philos_threads(t_data *data);
int		join_observation_threads(t_data *data);

//philo print utils
void	philo_taken_fork_printing(t_philo *philo);
void	philo_eating_printing(t_philo *philo);
void	philo_sleeping_printing(t_philo *philo);
void	philo_thinking_printing(t_philo *philo);
void	philo_died_printing(t_philo *philo);

//philo utils
int		philo_eating(t_philo *philo);
void	philo_sleeping(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	philo_died(t_philo *philo);

//time utils
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);

//mutex utils
int		lock_mutex(pthread_mutex_t *mutex);
int		unlock_mutex(pthread_mutex_t *mutex);
int		increment_int_mutex(pthread_mutex_t *mutex, int *var, int val);

//observation utils
void	*observation_routine(void *arg);

#endif