/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observation_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:33:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/04/21 15:33:32 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int	check_if_somone_died(t_philo *philo)
{
	size_t	time_stamp;

	time_stamp = get_current_time() - ((philo->data->start_eating.tv_sec * 1000)
			+ (philo->data->start_eating.tv_usec / 1000));
	if (time_stamp >= philo->data->time_to_die)
		return (1);
	return (0);
}

void	*observation_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_if_somone_died(philo))
		{
			philo_died_printing(philo);
			exit(1);
		}
		usleep(500);
	}
	return (NULL);
}
