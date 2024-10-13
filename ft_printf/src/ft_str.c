/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:05:14 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/12 21:50:19 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_str(char *str)
{
	int	i;
	int	neg;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		neg = ft_char(str[i++]);
		if (neg == -1)
			return (-1);
	}
	return (i);
}
