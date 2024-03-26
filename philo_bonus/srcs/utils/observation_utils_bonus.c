/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observation_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:33:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/26 03:33:58 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int	check_if_somone_died(t_philo *philo)
{
	size_t	time_stamp;
	size_t	last_meal_time;

	if (philo->is_finished == 1)
		return (0);
	last_meal_time = philo->last_meal_time;
	time_stamp = get_current_time() - last_meal_time;
	if (time_stamp > philo->data->time_to_die)
		return (1);
	return (0);
}

void	*observation_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->is_someone_died && !philo->is_finished)
	{
		if (philo->data->nbr_time_must_eat != -1
			&& philo->number_of_meals == philo->data->nbr_time_must_eat)
		{
			philo->is_finished = 1;
			break ;
		}
		if (check_if_somone_died(philo))
		{
			philo->data->is_someone_died = 1;
			philo_died_printing(philo);
			exit(1);
		}
		if (philo->data->is_someone_died)
			break ;
		usleep(100);
	}
	return (NULL);
}
