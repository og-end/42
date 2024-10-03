/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:42:00 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/03 23:34:04 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d_dst;
	const unsigned char	*s_src;

	if (!dst && !src)
		return (NULL);
	d_dst = (unsigned char *)dst;
	s_src = (const unsigned char *)src;
	if (d_dst > s_src)
	{
		while (len > 0)
		{
			len--;
			d_dst[len] = s_src[len];
		}
	}
	else
	{
		while (len > 0)
		{
			*d_dst++ = *s_src++;
			len--;
		}
	}
	return (dst);
}
