/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:21:05 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/15 04:43:24 by melachyr         ###   ########.fr       */
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

enum e_bool
{
	false,
	true
};

//fork struct
typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

//philo struct
typedef struct s_philo
{
	int			id;
	pthread_t	thread_id;
	t_fork		left_fork;
	t_fork		right_fork;
	size_t		number_of_meals;
	int			is_finished;
	int			is_dead;
	int			is_eating;
	size_t		last_meal_time;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
}	t_philo;

//tools
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strlen(const char *str);
char	*ft_trim(char *str);

//parsing
int		parsing(char **argv);

#endif