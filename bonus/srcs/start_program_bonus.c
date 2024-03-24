/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:03:47 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/24 23:14:05 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->is_someone_died)
	{
		if (philo->data->nbr_time_must_eat != -1
			&& philo->number_of_meals == philo->data->nbr_time_must_eat)
			{
				philo->is_finished = 1;
				break ;
			}
		if (check_if_somone_died(philo))
		{
			philo->data->is_someone_died = 1;
			philo_died_printing(philo);
			sem_post(philo->data->exit_sem);
		}
		if (philo->data->is_someone_died)
			break ;
		usleep(1000);
	}
	return (NULL);
}

void	*eat_observation_routine(void	*arg)
{
	t_data	*data;
	// int		i;
	// int		result;

	data = (t_data *)arg;
	while (1)
	{
		// i = 0;
		// result = 0;
		// while (i < data->number_of_philo)
		// {
		// 	// printf("philo %d is_finished = %d\n", data->philos[i].id, data->philos[i].is_finished);
		// 	if (data->philos[i].is_finished)
		// 	{
		// 		printf("philo %d finished\n", data->philos[i].id);	
		// 		result++;
		// 	}
		// 	i++;
		// }
		// printf("result = %d\n", result);
		if (data->nbr_philo_finished == data->number_of_philo - 1)
		{
			sem_post(data->exit_sem);
			break ;
		}
	}
	return (NULL);
}

void	kill_processes(t_data *data)
{
	int	i;

	i = 0;
	// printf("killing processes\n");
	while (data->number_of_philo)
	{
		kill(data->pid_philos[i], SIGTERM);
		i++;
	}
	sem_close(data->forks);
	sem_close(data->exit_sem);
	sem_close(data->wr_sem);
	sem_unlink("forks");
	sem_unlink("exit_sem");
	sem_unlink("wr_sem");
	free(data->pid_philos);
	free(data->philos);
}

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	data->started_time = get_current_time();
	if (pthread_create(&data->eat_monitor, NULL,
		&eat_observation_routine, data->philos) != 0)
	{
		ft_putstr_fd("Thread creation error\n", 2);
		exit(1);
	}
	while (i < data->number_of_philo)
	{
		data->pid_philos[i] = fork();
		if (data->pid_philos[i] == -1)
		{
			ft_putstr_fd("Fork error\n", 2);
			kill_processes(data);
			exit(1);
		}
		data->philos[i].last_meal_time = get_current_time();
		if (!data->pid_philos[i])
		{
			data->philos[i].id = i + 1;
			data->philos[i].pid = data->pid_philos[i];
			if (pthread_create(&data->philos[i].monitor, NULL,
				&observation_routine, &data->philos[i]) != 0)
			{
				ft_putstr_fd("Thread creation error\n", 2);
				exit(1);
			}
			pthread_detach(data->philos[i].monitor);
			if (data->philos[i].id % 2 == 0)
				ft_usleep(100);
			while (!data->philos[i].is_finished)
			{
				// if (data->philos[i].is_finished)
				// 	break ;
				sem_wait(data->forks);
				philo_taken_fork_printing(&data->philos[i]);
				sem_wait(data->forks);
				philo_taken_fork_printing(&data->philos[i]);
				data->philos[i].last_meal_time = get_current_time();
				data->philos[i].number_of_meals++;
				philo_eating_printing(&data->philos[i]);
				ft_usleep(data->time_to_eat);
				sem_post(data->forks);
				sem_post(data->forks);
				if (data->nbr_time_must_eat != -1
					&& data->philos[i].number_of_meals == data->philos[i].data->nbr_time_must_eat)
				{
					data->philos[i].is_finished = 1;
					return ;
				}
				philo_sleeping_printing(&data->philos[i]);
				ft_usleep(data->time_to_sleep);
				philo_thinking_printing(&data->philos[i]);
			}
			sem_wait(data->sem);
			data->nbr_philo_finished++;
			sem_post(data->sem);
		}		
		i++;
	}
	
}

void	start_program(t_data *data)
{
	init_semephores(data);
	create_philos(data);
	sem_wait(data->exit_sem);
	kill_processes(data);
}
