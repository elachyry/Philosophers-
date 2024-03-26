/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:15:39 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/26 04:00:00 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	wait_processes(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->number_of_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			killing_processes(data);
			break ;
		}
		i++;
	}
}

void	killing_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		kill(data->pid_philos[i], SIGTERM);
		i++;
	}
}

void	free_data(t_data *data)
{
	if (data->philos != NULL)
	{
		free(data->philos);
		data->philos = NULL;
	}
	if (data->pid_philos != NULL)
	{
		free(data->pid_philos);
		data->pid_philos = NULL;
	}
	sem_close(data->forks);
	sem_close(data->wr_sem);
	sem_unlink("/forks_sem");
	sem_unlink("/wr_sem");
}
