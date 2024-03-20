/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:57:16 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/19 16:40:03 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (1);
	if (!parsing(argv))
		return (1);
	init_variables(&data, argv);
	start_program(&data);
	if (!free_data(&data))
		return (1);
	return (0);
}
	// printf("number_of_philo %zu\n", data.number_of_philo);
	// printf("time_to_die %zu\n", data.time_to_die);
	// printf("time_to_eat %zu\n", data.time_to_eat);
	// printf("time_to_sleep %zu\n", data.time_to_sleep);
	// printf("nbr_time_must_eat %d\n", data.nbr_time_must_eat);
	
	// for (int i = 0; i < data.number_of_philo; i++)
	// {
	// 	printf("left fork of philo %d is %d\n",i + 1, data.philos->left_fork->id);
	// 	printf("right fork of philo %d is %d\n\n",i + 1, data.philos->right_fork->id);
	// 	data.philos++;
	// }