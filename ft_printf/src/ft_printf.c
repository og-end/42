/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:44:59 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/16 22:53:28 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_conversion(char s, va_list *args)
{
	int		counter;

	counter = 0;
	if (s == 'c')
		counter = ft_char(va_arg(*args, int));
	else if (s == 's')
		counter = ft_str(va_arg(*args, char *));
	else if (s == 'p')
		counter = ft_pointer(va_arg(*args, void *));
	else if (s == 'd' || s == 'i')
		counter = ft_decimal(va_arg(*args, int));
	else if (s == 'u')
		counter = ft_unsigned_decimal(va_arg(*args, unsigned int));
	else if (s == 'x')
		counter = ft_hexa(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (s == 'X')
		counter = ft_hexa(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (s == '%')
		return (ft_char('%'));
	return (counter);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_conversion(s[i], &args);
		}
		else
			count += ft_char(s[i]);
		i++;
	}
	return (va_end(args), count);
}
