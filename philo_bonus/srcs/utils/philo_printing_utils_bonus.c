/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_printing_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:46:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/23 03:37:06 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	philo_taken_fork_printing(t_philo *philo)
{
	size_t	time_stamp;

	if (philo->is_finished)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	sem_wait(philo->data->wr_sem);
	if (!philo->data->is_someone_died)
		printf("%zu %d has taken a fork\n", time_stamp, philo->id);
	sem_post(philo->data->wr_sem);
}

void	philo_eating_printing(t_philo *philo)
{
	size_t	time_stamp;

	if (philo->is_finished)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	sem_wait(philo->data->wr_sem);
	if (!philo->data->is_someone_died)
		printf("%zu %d is eating\n", time_stamp, philo->id);
	sem_post(philo->data->wr_sem);
}

void	philo_sleeping_printing(t_philo *philo)
{
	size_t	time_stamp;

	if (philo->is_finished)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	sem_wait(philo->data->wr_sem);
	if (!philo->data->is_someone_died)
		printf("%zu %d is sleeping\n", time_stamp, philo->id);
	sem_post(philo->data->wr_sem);
}

void	philo_thinking_printing(t_philo *philo)
{
	size_t	time_stamp;

	if (philo->is_finished)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	sem_wait(philo->data->wr_sem);
	if (!philo->data->is_someone_died)
		printf("%zu %d is thinking\n", time_stamp, philo->id);
	sem_post(philo->data->wr_sem);
}

void	philo_died_printing(t_philo *philo)
{
	size_t	time_stamp;

	if (philo->is_finished)
		return ;
	time_stamp = get_current_time() - philo->data->started_time;
	sem_wait(philo->data->wr_sem);
	if (philo->data->is_someone_died)
		printf("%zu %d died\n", time_stamp, philo->id);
	sem_post(philo->data->wr_sem);
}
