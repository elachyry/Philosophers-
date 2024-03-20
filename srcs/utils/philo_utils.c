/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:21:39 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/20 02:27:19 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	philo_eating(t_philo *philo)
{
	// printf("%d before philo_taken_fork_1\n", philo->id);
	if (!lock_mutex(&philo->first_fork->fork, 5))
		return ;
	philo_taken_fork_printing(philo);
	// printf("%d after philo_taken_fork_1\n", philo->id);
	// printf("%d before philo_taken_fork_2\n", philo->id);
	if (!lock_mutex(&philo->second_fork->fork, 6))
		return ;
	philo_taken_fork_printing(philo);
	// if (!set_sizet_mutex(&philo->philo_mutex,
	// 	&philo->last_meal_time, get_current_time()))
	// 	return ;
	philo->last_meal_time = get_current_time();
	philo->number_of_meals++;
	philo_eating_printing(philo);
	ft_usleep(philo->data->time_to_eat);
	if (philo->data->nbr_time_must_eat != -1
		&& philo->number_of_meals == philo->data->nbr_time_must_eat)
	{
		philo->is_finished = 1;
		// if (!set_int_mutex(&philo->philo_mutex, &philo->is_finished, 1))
		// 	return ;
	}
	if (!unlock_mutex(&philo->first_fork->fork))
		return ;
	if (!unlock_mutex(&philo->second_fork->fork))
		return ;
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
