/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:52 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/24 02:55:20 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	init_data(t_data *data, char **argv)
{
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->started_time = 0;
	data->is_someone_died = 0;
	data->nbr_philo_finished = 0;
	if (argv[5] != NULL)
		data->nbr_time_must_eat = ft_atoi(argv[5]);
	else
		data->nbr_time_must_eat = -1;
}

void	init_semephores(t_data *data)
{
	sem_unlink("/forks_sem");
	data->forks = sem_open("/forks_sem", O_CREAT, 0644, data->number_of_philo);
	sem_unlink("/wr_sem");
	data->wr_sem = sem_open("/wr_sem", O_CREAT, 0644, 1);
	sem_unlink("/sem");
	data->sem = sem_open("/sem", O_CREAT, 0644, 1);
	sem_unlink("/exit_sem");
	data->exit_sem = sem_open("/exit_sem", O_CREAT, 0644, 0);
	if (data->forks == SEM_FAILED || data->wr_sem == SEM_FAILED || data->exit_sem == SEM_FAILED)
	{
		ft_putstr_fd("Semaphore error\n", 2);
		exit (1);
	}
}

void	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->number_of_philo);
	if (data->philos == NULL)
		exit(1);
	data->pid_philos = malloc(sizeof(pid_t) * data->number_of_philo);
	if (data->pid_philos == NULL)
		exit(1);
	i = 0;
	while (i < data->number_of_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].is_finished = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].number_of_meals = 0;
		data->philos[i].data = data;
		i++;
	}
}

void	init_variables(t_data *data, char **argv)
{
	init_data(data, argv);
	init_philos(data);
}
