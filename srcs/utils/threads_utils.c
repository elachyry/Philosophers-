/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:21:25 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/21 07:48:41 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	create_philos_threads(t_data *data)
{
	int	i;

	if (data->number_of_philo == 1)
	{
		if (pthread_create(&data->philos[0].thread, NULL,
				&one_philo_routine, &data->philos[0]) != 0)
		{
			ft_putstr_fd("Thread creation error!\n", 2);
			return (0);
		}
	}
	else
	{
		i = -1;
		while (++i < data->number_of_philo)
		{
			if (pthread_create(&data->philos[i].thread, NULL,
					&philos_routine, &data->philos[i]) != 0)
			{
				ft_putstr_fd("Thread creation error!\n", 2);
				return (0);
			}
		}
	}
	return (1);
}

int	create_observation_thread(t_data *data)
{
	if (pthread_create(&data->monitor, NULL,
			&observation_routine, data) != 0)
	{
		ft_putstr_fd("Thread creation error!\n", 2);
		return (0);
	}
	return (1);
}

int	join_philos_threads(t_data *data)
{
	int		i;
	void	*result;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_join(data->philos[i].thread, &result) != 0)
		{
			ft_putstr_fd("Thread join error!\n", 2);
			return (0);
		}
		if (result == (void *)-1)
			return (0);
		i++;
	}
	return (1);
}

int	join_observation_threads(t_data *data)
{
	void	*result;

	if (pthread_join(data->monitor, &result) != 0)
	{
		ft_putstr_fd("Thread join error!\n", 2);
		return (0);
	}
	if (result == (void *)-1)
		return (0);
	return (1);
}
