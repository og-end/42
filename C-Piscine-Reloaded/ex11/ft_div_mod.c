/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antares <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:20:39 by antares           #+#    #+#             */
/*   Updated: 2024/09/21 20:34:03 by antares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	div;
		int	mod;

		ft_div_mod(atoi(av[1]), atoi(av[2]), &div, &mod);
		
		printf("%d divisé par %d = %d\n", atoi(av[1]), atoi(av[2]), div);
		printf("reste = %d\n", mod);

	}
	else
		printf("Usage: %s <number> <number>\n", av[0]);
}		
