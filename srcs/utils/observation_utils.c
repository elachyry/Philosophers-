/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observation_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:34:31 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/21 07:01:17 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_all_threads_starting(t_data *data)
{
	int	result;

	result = 0;
	if (!lock_mutex(&data->mutex, 12))
		return (-1);
	if (data->running_threads == data->number_of_philo)
		result = 1;
	else
		result = 0;
	if (!unlock_mutex(&data->mutex))
		return (-1);
	return (result);
}

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
	t_data	*data;
	int		result;
	int		i;

	data = (t_data *)arg;
	result = 0;
	while (!result)
	{
		result = is_all_threads_starting(data);
		if (result == -1)
		{
			write(2, "Error!\n", 7);
			return ((void *)-1);
		}
	}
	while (!data->is_someone_died)
	{
		i = -1;
		while (++i < data->number_of_philo && !data->is_someone_died)
		{
			if (check_if_somone_died(data->philos + i))
				philo_died(data->philos + i);
		}
	}
	return (NULL);
}
