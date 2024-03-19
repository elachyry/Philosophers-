/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observation_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:34:31 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/19 04:10:16 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_all_threads_starting(t_data *data)
{
	int	result;
	
	result = 0;
	if (!lock_mutex(&data->mutex_3, 12))
		return (-1);
	result = get_int_mutex(&data->mutex_4, &data->running_threads);
	if (result == data->number_of_philo)
		return (1);
	if (result == data->number_of_philo)
		result = 1;
	else
		result = 0;
	if (!unlock_mutex(&data->mutex_3))
		return (-1);
	return (result);
}

int	check_if_somone_died(t_philo *philo)
{
	size_t	time_stamp;
	size_t	last_meal_time;
	int		is_finished;

	is_finished = get_int_mutex(&philo->data->mutex_2, &philo->is_finished);
	// printf("I'm in!!\n");
	if (is_finished == -1)
		return (-1);
	else if (is_finished == 1)
		return (0);
	last_meal_time = get_sizet_mutex(&philo->data->mutex_2, &philo->last_meal_time);
	if (last_meal_time == -1)
		return (-1);
	// printf("last meal time = %zu\n", last_meal_time);
	time_stamp = get_current_time() - last_meal_time;
	// printf("timestamp = %zu | time to die = %zu | philo %d\n", time_stamp, philo->data->time_to_die, philo->id);
	if (time_stamp > philo->data->time_to_die)
		return (1);
	return (0);
}

void	*start_observation(void *arg)
{
	t_data	*data;
	int		result;
	int		i;
	
	data = (t_data *)arg;
	result = 0;
	// printf("------test\n");
	while (!result)
	{
		result = is_all_threads_starting(data);
		if (result == -1)
		{
			write(2, "Error!\n", 7);
			return ((void *)-1);
		}
	}
	sleep(1);
	result = 0;
	while (!is_someone_died(data))
	{
		// result = is_someone_died(data);
		// if (result == -1)
		// {
		// 	write(2, "Error!\n", 7);
		// 	return ((void *)-1);
		// }
		i = 0;
		// printf("test1\n");
		while (i < data->number_of_philo && !is_someone_died(data))
		{
			// printf("result %d\n", i);
			if (check_if_somone_died(data->philos + i))
			{
				if (!set_int_mutex(&data->mutex_2, &data->is_someone_died, 1))
					return ((void *)-1);
				philo_died_printing(data->philos + i);
			}
			// result = is_someone_died(data);
			// if (result == -1)
			// {
			// 	write(2, "Error!\n", 7);
			// 	return ((void *)-1);
			// }
			i++;
		}
	}
	return (NULL);
}
