/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observation_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:33:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/04/20 12:11:41 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

size_t get_last_meal_time(t_philo *philo) {
    size_t time;
    sem_wait(philo->data->sem);
    time = philo->last_meal_time;
    sem_post(philo->data->sem);
    return time;
}

int	check_if_somone_died(t_philo *philo)
{
	size_t	time_stamp;

	if (philo->is_finished == 1)
		return (0);
	// sem_wait(philo->data->sem_2);
	time_stamp = get_current_time() - get_last_meal_time(philo);
	// sem_post(philo->data->sem_2);
	if (time_stamp > philo->data->time_to_die)
		return (1);
	return (0);
}

void	*observation_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->is_someone_died && !philo->is_finished)
	{
		sem_wait(philo->data->meals_sem);
		if (philo->data->nbr_time_must_eat != -1
			&& philo->number_of_meals == philo->data->nbr_time_must_eat)
		{
			sem_wait(philo->data->dead_sem);
			philo->is_finished = 1;
			sem_post(philo->data->dead_sem);
			sem_post(philo->data->meals_sem);
			break ;
		}
		sem_post(philo->data->meals_sem);
		if (check_if_somone_died(philo))
		{
			sem_wait(philo->data->dead_sem);
			philo->data->is_someone_died = 1;
			sem_post(philo->data->dead_sem);
			philo_died_printing(philo);
			exit(1);
		}
		if (philo->data->is_someone_died)
			break ;
		usleep(500);
	}
	return (NULL);
}
