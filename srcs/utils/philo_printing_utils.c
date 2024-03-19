/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_printing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:46:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/19 03:37:11 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	philo_taken_fork_printing(t_philo *philo)
{
	size_t	time_stamp;
	int		someone_died;

	if (philo->is_finished)
		return ;
	someone_died = is_someone_died(philo->data);
	if (someone_died == -1)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	lock_mutex(&philo->data->mutex_2, 7);
	if (!someone_died)
		printf("%zu %d has taken a fork\n", time_stamp, philo->id);
	unlock_mutex(&philo->data->mutex_2);
}

void	philo_eating_printing(t_philo *philo)
{
	size_t	time_stamp;
	int		someone_died;

	if (philo->is_finished)
		return ;
	someone_died = is_someone_died(philo->data);
	if (someone_died == -1)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	lock_mutex(&philo->data->mutex_2, 8);
	if (!someone_died)
		printf("%zu %d is eating\n", time_stamp, philo->id);
	unlock_mutex(&philo->data->mutex_2);
}

void	philo_sleeping_printing(t_philo *philo)
{
	size_t	time_stamp;
	int		someone_died;

	if (philo->is_finished)
		return ;
	someone_died = is_someone_died(philo->data);
	if (someone_died == -1)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	lock_mutex(&philo->data->mutex_2, 9);
	if (!someone_died)
		printf("%zu %d is sleeping\n", time_stamp, philo->id);
	unlock_mutex(&philo->data->mutex_2);
}

void	philo_thinking_printing(t_philo *philo)
{
	size_t	time_stamp;
	int		someone_died;

	if (philo->is_finished)
		return ;
	someone_died = is_someone_died(philo->data);
	if (someone_died == -1)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	lock_mutex(&philo->data->mutex_2, 10);
	if (!someone_died)
		printf("%zu %d is thinking\n", time_stamp, philo->id);
	unlock_mutex(&philo->data->mutex_2);
}

void	philo_died_printing(t_philo *philo)
{
	size_t	time_stamp;
	int		someone_died;

	if (philo->is_finished)
		return ;
	someone_died = is_someone_died(philo->data);
	if (someone_died == -1)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	lock_mutex(&philo->data->mutex_2, 11);
	if (someone_died)
		printf("%zu %d died\n", time_stamp, philo->id);
	unlock_mutex(&philo->data->mutex_2);
}
