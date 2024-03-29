/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:57:16 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/22 04:07:26 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		result;

	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("args must be 4 or 5!\n", 2);
		return (1);
	}
	result = 0;
	if (!parsing(argv))
		return (1);
	if (!init_variables(&data, argv))
		result = 1;
	if (!result && !start_program(&data))
		result = 1;
	if (!free_data(&data))
		result = 1;
	return (result);
}

// for (int i = 0; i < data.number_of_philo; i++)
// {
// 	printf("firs fork of philo %d is %d\n",i + 1,
		// data.philos->first_fork->id);
// 	printf("second fork of philo %d is %d\n\n",i + 1,
		// data.philos->second_fork->id);
// 	data.philos++;
// }