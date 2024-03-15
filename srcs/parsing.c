/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:11:48 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/15 04:33:06 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_for_zeros(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int	check_for_non_numbers(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		// printf("atoi = %d | trim = %s | strcmp = %d\n",ft_atoi(argv[i]), ft_trim(argv[i]),ft_strcmp(ft_trim(argv[i]), "0"));
		if (ft_atoi(argv[i]) == 0)
		{
			if (!check_for_zeros(ft_trim(argv[i])))
				return (0);
		}
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
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		printf("Time_to_die or time_to_eat or time_to_sleep values cannot be lower than 60 ms!\n");
		return (0);
	}
	return (1);
}
