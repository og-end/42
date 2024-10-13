/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:12:59 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/10 02:00:54 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static unsigned int	ft_numlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_utoa(unsigned int c)
{
	char			*str;
	unsigned int	len;
	unsigned int	n;

	len = ft_numlen(c);
	n = c;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = n % 10 + 48;
		n /= 10;
	}
	str[ft_numlen(c)] = '\0';
	return (str);
}

int	ft_unsigned_decimal(unsigned int c)
{
	char	*str;
	int		size;

	if (c == 0)
		return (write(1, "0", 1));
	str = ft_utoa(c);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}
