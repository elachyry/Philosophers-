/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:52 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/19 03:06:54 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_data(t_data *data, char **argv)
{
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->is_all_thread_created = 0;
	data->started_time = 0;
	data->running_threads = 0;
	data->is_someone_died = 0;
	if (pthread_mutex_init(&data->mutex, NULL) != 0
		|| pthread_mutex_init(&data->mutex_2, NULL) != 0
		|| pthread_mutex_init(&data->mutex_3, NULL) != 0
		|| pthread_mutex_init(&data->mutex_4, NULL) != 0)
	{
		printf("Mutex error!");
		return ;
	}
	if (argv[5] != NULL)
		data->nbr_time_must_eat = ft_atoi(argv[5]);
	else
		data->nbr_time_must_eat = -1;
}

void	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(t_fork) * data->number_of_philo);
	if (data->forks == NULL)
		return ;
	i = 0;
	while (i < data->number_of_philo)
	{
		data->forks[i].id = i + 1;
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
		{
			printf("Mutex error!");
			return ;
		}
		i++;
	}
}

void	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->number_of_philo);
	if (data->philos == NULL)
		return ;
	i = 0;
	while (i < data->number_of_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].is_finished = 0;
		data->philos[i].is_dead = 0;
		data->philos[i].is_eating = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].number_of_meals = 0;
		// data->philos[i].thread = NULL;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos->philo_mutex, NULL) != 0)
		{
			printf("Mutex error!");
			return ;
		}
		// data->philos[i].right_fork = &data->forks[i];
		// if (i == 0)
		// 	data->philos[i].left_fork
		// 		= &data->forks[data->number_of_philo - 1];
		// else
		// 	data->philos[i].left_fork = &data->forks[i - 1];
		data->philos[i].first_fork = &data->forks[(i + 1) % data->number_of_philo];
		data->philos[i].second_fork = &data->forks[i];
		if (data->philos[i].id % 2 == 0)
		{
			data->philos[i].second_fork = &data->forks[(i + 1) % data->number_of_philo];
			data->philos[i].first_fork = &data->forks[i];
		}
		i++;
	}
}

void	init_variables(t_data *data, char **argv)
{
	init_data(data, argv);
	init_forks(data);
	init_philos(data);
}
