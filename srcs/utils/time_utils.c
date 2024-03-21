/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 02:00:27 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/21 04:04:43 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	struct timeval	start;
	struct timeval	current;
	size_t			elapsed_time;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(1000);
		gettimeofday(&current, NULL);
		elapsed_time = (current.tv_sec - start.tv_sec) * 1000
			+ (current.tv_usec - start.tv_usec) / 1000;
		if (elapsed_time >= milliseconds)
			break ;
	}
}
