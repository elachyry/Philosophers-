/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_printing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:46:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/04/23 16:40:19 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	philo_taken_fork_printing(t_philo *philo)
{
	size_t	time_stamp;

	lock_mutex(&philo->data->mutex_3);
	if (philo->is_finished || philo->data->is_someone_died)
	{
		unlock_mutex(&philo->data->mutex_3);
		return ;
	}
	unlock_mutex(&philo->data->mutex_3);
	lock_mutex(&philo->philo_mutex);
	time_stamp = get_current_time() - philo->data->started_time;
	printf("%zu %d has taken a fork\n", time_stamp, philo->id);
	unlock_mutex(&philo->philo_mutex);
}

void	philo_eating_printing(t_philo *philo)
{
	size_t	time_stamp;

	lock_mutex(&philo->data->mutex_3);
	if (philo->is_finished || philo->data->is_someone_died)
	{
		unlock_mutex(&philo->data->mutex_3);
		return ;
	}
	unlock_mutex(&philo->data->mutex_3);
	lock_mutex(&philo->philo_mutex);
	time_stamp = get_current_time() - philo->data->started_time;
	printf("%zu %d is eating\n", time_stamp, philo->id);
	unlock_mutex(&philo->philo_mutex);
}

void	philo_sleeping_printing(t_philo *philo)
{
	size_t	time_stamp;

	lock_mutex(&philo->data->mutex_3);
	if (philo->is_finished || philo->data->is_someone_died)
	{
		unlock_mutex(&philo->data->mutex_3);
		return ;
	}
	unlock_mutex(&philo->data->mutex_3);
	lock_mutex(&philo->philo_mutex);
	time_stamp = get_current_time() - philo->data->started_time;
	printf("%zu %d is sleeping\n", time_stamp, philo->id);
	unlock_mutex(&philo->philo_mutex);
}

void	philo_thinking_printing(t_philo *philo)
{
	size_t	time_stamp;

	lock_mutex(&philo->data->mutex_3);
	if (philo->is_finished || philo->data->is_someone_died)
	{
		unlock_mutex(&philo->data->mutex_3);
		return ;
	}
	unlock_mutex(&philo->data->mutex_3);
	lock_mutex(&philo->philo_mutex);
	time_stamp = get_current_time() - philo->data->started_time;
	printf("%zu %d is thinking\n", time_stamp, philo->id);
	unlock_mutex(&philo->philo_mutex);
}

void	philo_died_printing(t_philo *philo)
{
	size_t	time_stamp;

	lock_mutex(&philo->data->mutex_3);
	if (philo->is_finished && !philo->data->is_someone_died)
	{
		unlock_mutex(&philo->data->mutex_3);
		return ;
	}
	unlock_mutex(&philo->data->mutex_3);
	lock_mutex(&philo->philo_mutex);
	time_stamp = get_current_time() - philo->data->started_time;
	printf("%zu %d died\n", time_stamp, philo->id);
	unlock_mutex(&philo->philo_mutex);
}
