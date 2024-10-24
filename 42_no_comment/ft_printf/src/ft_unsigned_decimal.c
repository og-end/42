/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:12:59 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/17 16:02:34 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_unsigned_decimal(unsigned int c)
{
	char	buffer[11];
	int		i;
	int		count;

	i = 10;
	buffer[i] = '\0';
	if (c == 0)
		buffer[--i] = '0';
	while (c)
	{
		buffer[--i] = (c % 10) + '0';
		c /= 10;
	}
	count = ft_str(&buffer[i]);
	return (count);
}
