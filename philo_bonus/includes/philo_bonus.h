/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:21:05 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/26 03:44:43 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct s_data	t_data;

//philo struct
typedef struct s_philo
{
	int				id;
	pthread_t		monitor;
	pthread_t		eat;
	int				number_of_meals;
	int				is_finished;
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
	int				is_someone_died;
	size_t			started_time;
	t_philo			*philos;
	pid_t			*pid_philos;
	sem_t			*wr_sem;
	sem_t			*forks;
	int				nbr_philo_finished;
}	t_data;

//tools
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strlen(const char *str);
char	*ft_trim(char *str);
void	ft_putstr_fd(char *s, int fd);

//parsing
void	parsing(char **argv);

//init variables
void	init_variables(t_data *data, char **argv);
void	init_semephores(t_data *data);

//free data
void	free_data(t_data *data);
void	wait_processes(t_data *data);
void	killing_processes(t_data *data);

//start program
void	start_program(t_data *data);

//philo print utils
void	philo_taken_fork_printing(t_philo *philo);
void	philo_eating_printing(t_philo *philo);
void	philo_sleeping_printing(t_philo *philo);
void	philo_thinking_printing(t_philo *philo);
void	philo_died_printing(t_philo *philo);

//philo utils
void	philo_eating(t_data *data, int i);
void	philo_sleeping(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	philo_died(t_philo *philo);

//observation utils
void	*observation_routine(void *arg);

//time utils
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);

#endif