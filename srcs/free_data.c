/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:11:16 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/21 07:05:23 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	destroy_mutex(pthread_mutex_t *mutex, int position)
{
	if (pthread_mutex_destroy(mutex) != 0)
	{
		write(2, "Mutex destroy error!\n", 22);
		return (0);
	}
	return (1);
}

int	free_data(t_data *data)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < data->number_of_philo)
	{
		if (!destroy_mutex(&data->forks[i].fork, i))
			result = 0;
		if (!destroy_mutex(&data->philos[i++].philo_mutex, i + 100))
			result = 0;
	}
	if (!destroy_mutex(&data->mutex, -1))
		result = 0;
	free(data->forks);
	free(data->philos);
	return (result);
}
