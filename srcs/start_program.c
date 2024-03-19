/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:34:29 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/19 04:15:28 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_someone_died(t_data *data)
{
	int	result;

	result = get_int_mutex(&data->mutex_2, &data->is_someone_died);
	if (result == -1)
	{
		write(2, "Error!\n", 7);
		return (-1);
	}
	return (result);
}

void	*start_eating(void *arg)
{
	t_philo	*philo;
	int		result;

	philo = (t_philo *)arg;
	result = 0;
	while (!result)
	{
		result = get_int_mutex(&philo->data->mutex,
				&philo->data->is_all_thread_created);
		if (result == -1)
		{
			write(2, "Error1!\n", 7);
			return ((void *)-1);
		}
	}
	if (!set_sizet_mutex(&philo->data->mutex_2, &philo->last_meal_time, get_current_time()))
		return ((void *)-1);
	if (!increment_int_mutex(&philo->data->mutex,
		&philo->data->running_threads, 1))
		return ((void *)-1);
	// printf("running_threads = %d\n", get_int_mutex(&philo->data->mutex_2, &philo->data->running_threads));
	result = 0;
	while (!result)
	{
		result = is_someone_died(philo->data);
		// printf("someone died = %d\n", result);
		if (result == -1)
		{
			write(2, "Error!\n", 7);
			return ((void *)-1);
		}
		if (philo->is_finished)
			break ;
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (NULL);
}

void	*lonely_philo(void *arg)
{
	t_philo	*philo;
	int		result;

	philo = (t_philo *)arg;
	result = 0;
	while (!result)
	{
		result = get_int_mutex(&philo->data->mutex,
				&philo->data->is_all_thread_created);
		if (result == -1)
		{
			write(2, "Error!\n", 7);
			return ((void *)-1);
		}
	}
	if (!set_sizet_mutex(&philo->data->mutex_2, &philo->last_meal_time, get_current_time()))
		return ((void *)-1);
	if (!increment_int_mutex(&philo->data->mutex,
		&philo->data->running_threads, 1))
		return ((void *)-1);
	philo_taken_fork_printing(philo);
	result = 0;
	while (!result)
	{
		result = is_someone_died(philo->data);
		if (result == -1)
		{
			write(2, "Error!\n", 7);
			return ((void *)-1);
		}
		usleep(200);
	}
	return (NULL);
}

int	start_program(t_data *data)
{
	int	i;
	
	// printf("nbr_time_must_eat = %d\n", data->nbr_time_must_eat);
	if (data->nbr_time_must_eat == 0)
		return (1);
	else if (data->nbr_time_must_eat == 1)
	{
		if (pthread_create(&data->philos[0].thread, NULL,
				&lonely_philo, &data->philos[0]) != 0)
		{
			printf("Thread creation error!\n");
			return (0);
		}
	}

	i = 0;
	while (i < data->number_of_philo)
	{
		// printf("test\n");
		if (pthread_create(&data->philos[i].thread, NULL,
				&start_eating, &data->philos[i]) != 0)
		{
			printf("Thread creation error!\n");
			return (0);
		}
		i++;
	}
	if (pthread_create(&data->monitor, NULL,
			&start_observation, data) != 0)
	{
		printf("Thread creation error!\n");
		return (0);
	}
	data->started_time = get_current_time();
	if (!set_int_mutex(&data->mutex, &data->is_all_thread_created, 1))
		return (0);
	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
		{
			printf("Thread join error!\n");
			return (0);
		}
		i++;
	}
	if (!set_int_mutex(&data->mutex_2, &data->is_someone_died, 1))
		return (0);
	if (pthread_join(data->monitor, NULL) != 0)
	{
		printf("Thread join error!\n");
		return (0);
	}
	return (1);
}
