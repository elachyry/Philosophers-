/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:33:07 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/21 07:49:29 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		ft_putstr_fd("Mutex lock error!\n", 2);
		return (0);
	}
	return (1);
}

int	unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		ft_putstr_fd("Mutex unlock error!\n", 2);
		return (0);
	}
	return (1);
}

int	increment_int_mutex(pthread_mutex_t *mutex, int *var, int val)
{
	if (!lock_mutex(mutex))
		return (0);
	*var += val;
	if (!unlock_mutex(mutex))
		return (0);
	return (1);
}

// int	set_int_mutex(pthread_mutex_t *mutex, int *var, int val)
// {
// 	if (!lock_mutex(mutex, 0))
// 		return (0);
// 	*var = val;
// 	if (!unlock_mutex(mutex))
// 		return (0);
// 	return (1);
// }
// int	get_int_mutex(pthread_mutex_t *mutex, int *var)
// {
// 	int	val;

// 	if (!lock_mutex(mutex, 2))
// 		return (-1);
// 	val = *var;
// 	if (!unlock_mutex(mutex))
// 		return (-1);
// 	return (val);
// }
// size_t	get_sizet_mutex(pthread_mutex_t *mutex, size_t *var)
// {
// 	size_t	val;

// 	if (!lock_mutex(mutex, 4))
// 		return (0);
// 	val = *var;
// 	if (!unlock_mutex(mutex))
// 		return (0);
// 	return (val);
// }
// int	set_sizet_mutex(pthread_mutex_t *mutex, size_t *var, size_t val)
// {
// 	if (!lock_mutex(mutex, 3))
// 		return (0);
// 	*var = val;
// 	if (!unlock_mutex(mutex))
// 		return (0);
// 	return (1);
// }