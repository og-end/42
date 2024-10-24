/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:33:25 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/23 18:13:13 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_putnbr_base(unsigned long tmp, char *base)
{
	if (tmp >= 16)
		ft_putnbr_base(tmp / 16, base);
	write(1, &base[tmp % 16], 1);
}

int	ft_pointer(void *ptr)
{
	unsigned long	count;
	unsigned long	tmp;

	tmp = (unsigned long)ptr;
	count = write(1, "0x", 2);
	if (tmp == 0)
		count += write(1, "0", 1);
	else
	{
		ft_putnbr_base(tmp, "0123456789abcdef");
		while (tmp > 0)
		{
			tmp /= 16;
			count++;
		}
	}
	return (count);
}
