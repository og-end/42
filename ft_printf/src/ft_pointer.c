/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:33:25 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/13 00:53:55 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_base(unsigned long tmp, char *base)
{
	int	count;

	count = 0;
	if (tmp >= 16)
		ft_putnbr_base(tmp / 16, base);
	count += write(1, &base[tmp % 16], 1);
	return (count);
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
