/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 04:10:38 by melachyr          #+#    #+#             */
/*   Updated: 2024/04/22 12:43:03 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("args must be 4 or 5!\n", 2);
		exit(1);
	}
	parsing(argv);
	init_variables(&data, argv);
	start_program(&data);
	free_data(&data);
	return (0);
}
