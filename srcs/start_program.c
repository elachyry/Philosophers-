/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:34:29 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/21 06:24:19 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philos_routine(void *arg)
{
	t_philo	*philo;
	int		result;

	philo = (t_philo *)arg;
	result = 0;
	while (!philo->data->is_all_thread_created)
		;
	philo->last_meal_time = get_current_time();
	if (!increment_int_mutex(&philo->philo_mutex,
			&philo->data->running_threads, 1))
		return ((void *)-1);
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!philo->data->is_someone_died)
	{
		if (philo->is_finished)
			break ;
		if (!philo_eating(philo))
			continue ;
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (NULL);
}

void	*one_philo_routine(void *arg)
{
	t_philo	*philo;
	int		result;

	philo = (t_philo *)arg;
	result = 0;
	while (!philo->data->is_all_thread_created)
		;
	philo->last_meal_time = get_current_time();
	philo->data->running_threads++;
	philo_taken_fork_printing(philo);
	result = 0;
	while (!philo->data->is_someone_died)
		usleep(200);
	return (NULL);
}

int	start_program(t_data *data)
{
	int	i;

	if (data->nbr_time_must_eat == 0)
		return (1);
	if (!create_philos_threads(data))
		return (0);
	if (!create_observation_thread(data))
		return (0);
	data->started_time = get_current_time();
	data->is_all_thread_created = 1;
	if (!join_philos_threads(data))
		return (0);
	data->is_someone_died = 1;
	if (!join_observation_threads(data))
		return (0);
	return (1);
}
