/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:36:30 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/12 21:04:20 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_putnbr_base(unsigned int nbr, char *base)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
}

int	ft_hexa(unsigned int nbr, char *base)
{
	unsigned int	count;
	unsigned int	tmp;

	count = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	ft_putnbr_base(nbr, base);
	tmp = nbr;
	while (tmp > 0)
	{
		tmp /= 16;
		count++;
	}
	return (count);
}
