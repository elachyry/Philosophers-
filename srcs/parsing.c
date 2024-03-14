/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:11:48 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/14 01:51:58 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


int	check_if_only_numbers(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_for_non_numbers(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!check_if_only_numbers(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parsing(char **argv)
{
	if (!check_for_non_numbers(argv))
	{
		printf("args can be just numbers!\n");
		return (0);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		printf("The number of philosophers cannot be more the 200!\n");
		return (0);
	}
	return (1);
}
