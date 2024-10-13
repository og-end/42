/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:00:30 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/09 23:12:51 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_decimal(int c)
{
	char	*str;
	size_t	size;

	if (!c)
		return (write(1, "0", 1));
	str = ft_itoa(c);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}
