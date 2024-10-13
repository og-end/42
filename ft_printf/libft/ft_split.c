/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 04:48:08 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/07 00:10:18 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freelist(char **list, int word_i)
{
	int	i;

	i = 0;
	while (i < word_i)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static size_t	ft_countword(char const *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *)malloc((n + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < n)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**list;
	int			i;
	int			start;
	int			word_i;

	list = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	i = 0;
	word_i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
		{
			list[word_i] = ft_strndup(s + start, i - start);
			if (!list[word_i++])
				return (ft_freelist(list, word_i), NULL);
		}
	}
	return (list[word_i] = NULL, list);
}
