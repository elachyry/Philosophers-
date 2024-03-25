/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:15:39 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/25 03:15:55 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	free_data(t_data *data)
{
	free(data->philos);
	free(data->pid_philos);
	sem_close(data->forks);
	sem_close(data->wr_sem);
	sem_close(data->exit_sem);
	sem_unlink("/forks_sem");
	sem_unlink("/wr_sem");
	sem_unlink("/sem");
	sem_unlink("/exit_sem");
}
