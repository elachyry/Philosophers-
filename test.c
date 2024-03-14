/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:18:21 by melachyr          #+#    #+#             */
/*   Updated: 2024/03/13 23:31:54 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"
#include <time.h>

void	*rool_dice()
{
	int	*result;

	result = malloc(sizeof(int));
	if (result == NULL)
		return (NULL);
	*result = (rand() % 6) + 1;
	return (result); 
}

int	main()
{
	pthread_t	thread[4];
	int			*result;
	
	srand(time(NULL));

	for (int i = 0; i < 4; i++)
	{
		if (pthread_create(thread + i, NULL, &rool_dice, NULL) != 0)
			return (1);
	}
	for (int i = 0; i < 4; i++)
	{
		if (pthread_join(thread[i], (void **)&result) != 0)
			return (1);
		printf("result is %d\n", *result);
	}
	
	return (0);
}
