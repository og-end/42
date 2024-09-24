/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:41:30 by eahmeti           #+#    #+#             */
/*   Updated: 2024/09/24 15:41:40 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
/*#include <stdio.h>
int	main(int ac, char **av)
{
	int	min = atoi(av[1]);
	int	max = atoi(av[2]);
	int	*range = ft_range(min, max);
	int	i = 0;

	(void)ac;
	if (!range)
	{
		printf("Invalide range\n");
		return (1);
	}
	while (i < (max - min))
	{
		if ((i + 1) < (max - min))
		{
			printf("%d, ", range[i]);
			i++;
		}
		else
		{
			printf("%d\n", range[i]);
			i++;
		}
	}
	free(range);
	return (0);
}*/
