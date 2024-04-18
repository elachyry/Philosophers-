/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:34:29 by melachyr          #+#    #+#             */
/*   Updated: 2024/04/18 20:06:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philos_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		lock_mutex(&philo->data->mutex_2);
		if (philo->data->is_all_thread_created)
			break ;
		unlock_mutex(&philo->data->mutex_2);
	}
	philo->last_meal_time = get_current_time();
	if (!increment_int_mutex(&philo->data->mutex,
			&philo->data->running_threads, 1))
		return ((void *)-1);
	if (philo->id % 2 == 0)
		ft_usleep(60);
	while (!philo->data->is_someone_died)
	{
		if (philo->is_finished)
			break ;
		if (!philo_eating(philo))
			continue ;
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (NULL);
}

void	*one_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	lock_mutex(&philo->data->mutex);
	while (1)
	{
		if (philo->data->is_all_thread_created)
			break ;
	}
	unlock_mutex(&philo->data->mutex);
	philo->last_meal_time = get_current_time();
	philo->data->running_threads++;
	philo_taken_fork_printing(philo);
	while (!philo->data->is_someone_died)
		usleep(200);
	return (NULL);
}

int	start_program(t_data *data)
{
	if (data->nbr_time_must_eat == 0)
		return (1);
	if (!create_philos_threads(data))
		return (0);
	if (!create_observation_thread(data))
		return (0);
	data->started_time = get_current_time();
	lock_mutex(&data->mutex_2);
	data->is_all_thread_created = 1;
	unlock_mutex(&data->mutex_2);
	if (!join_philos_threads(data))
		return (0);
	data->is_someone_died = 1;
	if (!join_observation_threads(data))
		return (0);
	return (1);
}
