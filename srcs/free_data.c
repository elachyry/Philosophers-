/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:11:16 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/17 01:32:11 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
		pthread_mutex_destroy(&data->forks[i++].fork);
	free(data->forks);
	free(data->philos);
}
