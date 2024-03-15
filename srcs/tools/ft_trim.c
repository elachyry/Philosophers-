/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 04:00:57 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/15 04:01:22 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_white_spaces(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char	*ft_trim(char *str)
{
	char	*end;

	while (is_white_spaces(*str))
		str++;
	if (*str == '\0')
		return (str);
	end = str + (ft_strlen(str) - 1);
	while (end > str && is_white_spaces(*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}
