/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:21:39 by melachyr          #+#    #+#             */
/*   Updated: 2024/04/19 20:20:20 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	philo_eating(t_philo *philo)
{
	if (!lock_mutex(&philo->right_fork->fork))
		return (0);
	philo_taken_fork_printing(philo);
	if (!lock_mutex(&philo->left_fork->fork))
	{
		unlock_mutex(&philo->right_fork->fork);
		return (0);
	}
	philo_taken_fork_printing(philo);
	lock_mutex(&philo->data->mutex_4);
	philo->last_meal_time = get_current_time();
	unlock_mutex(&philo->data->mutex_4);
	philo->number_of_meals++;
	philo_eating_printing(philo);
	ft_usleep(philo->data->time_to_eat);
	if (philo->data->nbr_time_must_eat != -1
		&& philo->number_of_meals == philo->data->nbr_time_must_eat)
	{
		lock_mutex(&philo->data->mutex_5);
		philo->is_finished = 1;
		unlock_mutex(&philo->data->mutex_5);
	}
	unlock_mutex(&philo->right_fork->fork);
	unlock_mutex(&philo->left_fork->fork);
	return (1);
}

void	philo_sleeping(t_philo *philo)
{
	philo_sleeping_printing(philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	philo_thinking_printing(philo);
}

void	philo_died(t_philo *philo)
{
	lock_mutex(&philo->data->mutex_3);
	philo->data->is_someone_died = 1;
	unlock_mutex(&philo->data->mutex_3);
	philo_died_printing(philo);
}
