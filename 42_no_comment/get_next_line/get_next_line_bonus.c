/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:22:01 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/24 01:57:00 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_process_line(char *content)
{
	char	*line;
	int		i;

	if (!content || !content[0])
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
		line[i++] = '\n';
	return (line[i] = '\0', line);
}

static char	*ft_save_remaining(char *content)
{
	char	*remaining;
	int		i;
	int		j;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i] || !content[i + 1])
		return (free(content), NULL);
	remaining = malloc(sizeof(char) * (ft_strlen(content) - i));
	if (!remaining)
		return (free(content), NULL);
	i++;
	j = 0;
	while (content[i])
		remaining[j++] = content[i++];
	return (remaining[j] = '\0', free(content), remaining);
}

char	*get_next_line(int fd)
{
	static char	*reste[OPEN_MAX];
	char		*buffer;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(reste[fd], '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(reste[fd]), reste[fd] = NULL, NULL);
		buffer[bytes_read] = '\0';
		reste[fd] = ft_strjoin(reste[fd], buffer);
		if (!reste[fd])
			return (free(reste[fd]), NULL);
	}
	free(buffer);
	line = ft_process_line(reste[fd]);
	reste[fd] = ft_save_remaining(reste[fd]);
	return (line);
}
