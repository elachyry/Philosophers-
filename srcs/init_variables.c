/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:52 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/25 05:07:53 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_data(t_data *data, char **argv)
{
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->is_all_thread_created = 0;
	data->started_time = 0;
	data->running_threads = 0;
	data->is_someone_died = 0;
	if (pthread_mutex_init(&data->mutex, NULL) != 0)
	{
		ft_putstr_fd("Mutex error!\n", 2);
		return (0);
	}
	if (argv[5] != NULL)
		data->nbr_time_must_eat = ft_atoi(argv[5]);
	else
		data->nbr_time_must_eat = -1;
	return (1);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(t_fork) * data->number_of_philo);
	if (data->forks == NULL)
		return (0);
	i = 0;
	while (i < data->number_of_philo)
	{
		data->forks[i].id = i + 1;
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
		{
			ft_putstr_fd("Mutex error!\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	forks_affectation(t_data *data, int i)
{
	data->philos[i].left_fork = &data->forks[i];
	if (i == 0)
		data->philos[i].right_fork = &data->forks[data->number_of_philo - 1];
	else
		data->philos[i].right_fork = &data->forks[i - 1];
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->number_of_philo);
	if (data->philos == NULL)
		return (0);
	i = 0;
	while (i < data->number_of_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].is_finished = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].number_of_meals = 0;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].philo_mutex, NULL) != 0)
		{
			ft_putstr_fd("Mutex error!\n", 2);
			return (0);
		}
		forks_affectation(data, i);
		i++;
	}
	return (1);
}

int	init_variables(t_data *data, char **argv)
{
	if (!init_data(data, argv) || !init_forks(data) || !init_philos(data))
		return (0);
	return (1);
}
