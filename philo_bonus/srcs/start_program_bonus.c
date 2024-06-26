/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:03:47 by melachyr          #+#    #+#             */
/*   Updated: 2024/04/21 15:36:34 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	child_process(t_data *data, int i)
{
	if (!data->pid_philos[i])
	{
		if (pthread_create(&data->philos[i].monitor, NULL,
				&observation_routine, &data->philos[i]) != 0)
		{
			ft_putstr_fd("Thread creation error\n", 2);
			exit(1);
		}
		if (data->philos[i].id % 2 == 0)
			ft_usleep(60);
		while (1)
		{
			philo_eating(data, i);
			philo_sleeping(&data->philos[i]);
			philo_thinking(&data->philos[i]);
		}
		if (pthread_join(data->philos[i].monitor, NULL) != 0)
		{
			ft_putstr_fd("Thread join error\n", 2);
			exit(1);
		}
		exit(0);
	}
}

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	data->started_time = get_current_time();
	while (i < data->number_of_philo)
	{
		data->pid_philos[i] = fork();
		if (data->pid_philos[i] == -1)
		{
			ft_putstr_fd("Fork error\n", 2);
			exit(1);
		}
		child_process(data, i);
		i++;
	}
}

void	start_program(t_data *data)
{
	init_semephores(data);
	create_philos(data);
	wait_processes(data);
}
