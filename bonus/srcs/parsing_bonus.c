/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:11:48 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/23 01:39:32 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
		if (ft_atoi(argv[i]) == 0)
		{
			if (!check_for_zeros(ft_trim(argv[i])))
				return (0);
		}
		i++;
	}
	return (1);
}

void	check_for_int_max(char **argv)
{
	if (ft_strlen(argv[2]) > 10 || ft_strlen(argv[3]) > 10
		|| ft_strlen(argv[4]) > 10)
	{
		ft_putstr_fd("Time_to_die or time_to_eat or time_to_sleep\
		values cannot be lower than 0 or higher than INT_MAX!\n", 2);
		exit(1);
	}
	if (argv[5] != NULL)
	{
		if (ft_strlen(argv[5]) > 10)
		{
			ft_putstr_fd("Number_of_times_each_philosopher_must_eat\
			value cannot be lower than 0 or higher than INT_MAX!\n", 2);
			exit(1);
		}
	}
	if (ft_atoi(argv[2]) > INT_MAX || ft_atoi(argv[3]) > INT_MAX
		|| ft_atoi(argv[4]) > INT_MAX)
	{
		ft_putstr_fd("Time_to_die or time_to_eat or time_to_sleep\
		values cannot be higher than INT_MAX!\n", 2);
		exit(1);
	}
}

void	check_for_negative(char **argv)
{
	if (ft_atoi(argv[1]) < 0)
	{
		ft_putstr_fd("The number of philosophers cannot be lower than 0!\n", 2);
		exit(1);
	}
	if (argv[5] != NULL)
	{
		if (ft_atoi(argv[5]) < 0)
		{
			ft_putstr_fd("Number_of_times_each_philosopher_must_eat value \
			cannot be lower than 0!\n", 2);
			exit(1);
		}
	}
}

void	parsing(char **argv)
{
	if (!check_for_non_numbers(argv))
	{
		ft_putstr_fd("args can be just numbers!\n", 2);
		exit(1);
	}
	check_for_negative(argv);
	if (ft_atoi(argv[1]) > 200)
	{
		ft_putstr_fd("The number of philosophers cannot be more the 200!\n", 2);
		exit(1);
	}
	check_for_int_max(argv);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
	{
		ft_putstr_fd("Time_to_die or time_to_eat or time_to_sleep values \
		cannot be lower than 60 ms!\n", 2);
		exit(1);
	}
}
