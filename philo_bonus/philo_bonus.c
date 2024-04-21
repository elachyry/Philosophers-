/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 04:10:38 by melachyr          #+#    #+#             */
/*   Updated: 2024/04/21 21:58:45 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	main_2(int argc, char **argv)
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
	system("leaks philo_bonus");
	return (0);
}


int	main(int argc, char **argv)
{
	main_2( argc ,argv);
	system("leaks philo_bonus");
	
}
