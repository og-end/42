/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:02:56 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/07 00:10:44 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = dstsize - dst_len - 1;
	if (i > 0)
	{
		if (i > src_len)
			i = src_len;
		ft_memcpy(dst + dst_len, src, i);
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}
