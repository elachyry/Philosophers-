/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:21:39 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/25 05:08:24 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	philo_eating(t_data *data, int i)
{
	sem_wait(data->forks);
	philo_taken_fork_printing(&data->philos[i]);
	sem_wait(data->forks);
	philo_taken_fork_printing(&data->philos[i]);
	data->philos[i].last_meal_time = get_current_time();
	data->philos[i].number_of_meals++;
	philo_eating_printing(&data->philos[i]);
	ft_usleep(data->time_to_eat);
	sem_post(data->forks);
	sem_post(data->forks);
	if (data->nbr_time_must_eat != -1
		&& data->philos[i].number_of_meals
		== data->philos[i].data->nbr_time_must_eat)
	{
		data->philos[i].is_finished = 1;
		exit(0);
	}
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
	philo->data->is_someone_died = 1;
	philo_died_printing(philo);
}
