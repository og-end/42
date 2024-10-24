/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:07:00 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/24 23:33:43 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


			//	ft_process_line va garder tout ce qu'il
			//	y a avant le \n (inclus si il s'y trouve)
			//	elle retourne une nouvelle chaine
			//	de caractere se terminant par \0.


static char	*ft_process_line(char *content)
{
	char	*line;
	int		i;

					//	check : si content est vide, return NULL.

	if (!content || !content[0])
		return (NULL);

					//	avancer dans content tant qu'il n'est pas
					//	fini et qu'on ne voit pas de \n.
					//	verifier si on se trouve sur un \n
					//	et avancer pour pouvoir malloc line avec
					//	la place pour le \n et le \0.

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);

					//	on doit avancer dans content jusqu'a la
					//	premiere recurrence de \n ou \0.
					//	si c'est un \n l'ajouter dans la chaine
					//	line, avant de la conclure avec un \0.
					//	return line.

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






			//	ft_remaining va check si il reste quelque
			//	chose apres le /n.
			//	si il reste quelque chose, alors il va
			//	le stocker dans une nouvelle chaine de
			//	caractere, la terminer par un \0
			//	et la return.


static char	*ft_remaining(char *content)
{
	char	*remaining;
	int		i;
	int		j;

					//	avancer dans content jusqua la premiere
					//	de \n et verifier si i + 1 n'est pas null.
					//	si null, alors free(content et return NULL.

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i] || !content[i + 1])
		return (free(content), NULL);

					//	il faut malloc la taille depuis le \n,
					//	jusqu'au \0, et envoyer ca dans le reste.
					//	ne pas oublier d'ajouter le \0, et
					//	free le content.

	remaining = malloc(sizeof(char) * (ft_strlen(content) - i));
	if (!remaining)
		return (free(content), NULL);
	i++;
	j = 0;
	while (content[i])
		remaining[j++] = content[i++];
	return (remaining[j] = '\0', free(content), remaining);
}






			//	corps principal de la fonction GNL.
			//	declarer un static char *reste
			//	celle-ci conserve son contenu entre
			//	chaque appel de fonction.
			//	le reste stockera tout ce qui se trouve
			//	apres les \n rencontrer.
			//
			//	un buffer pour manipuler le texte lu
			//	par read.
			//
			//	un line qui va stocker la chaine de
			//	caractere jusqu'a la premiere occurence
			//	du \n. c'est ce line qui va ensuite etre 
			//	retourner.


char	*get_next_line(int fd)
{
	static char	*reste;
	char		*buffer;
	char		*line;
	int			bytes_read;

					//	d'abord check si fd et BUFFER_SIZE
					//	sont bien valide.
					//	malloc le char *buffer a la taille de
					//	BUFFER_SIZE + 1 pour le \0.

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);

					//	si ft_strchr retourne NULL cela veut dire
					//	qu'il n'a pas rencontrer de \n et donc 
					//	on va stocker notre buffer dans le reste (strjoin)
					//	pour pouvoir le conserver a la seconde iteration
					//	de la boucle while.
					//
					//	cette boucle ne sera plus executee le moment 
					//	ou on aura tout lu le fichier ou bien, que
					//	l'on aura trouver un \n.
					//
					//	comme au premier appel, reste est automatiquement
					//	initialise a NULL, cette boucle va s'executer
					//	pour la premiere fois.

	bytes_read = 1;
	while (!ft_strchr(reste, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(reste), reste = NULL, NULL);
		buffer[bytes_read] = '\0';
		reste = ft_strjoin(reste, buffer);
		if (!reste)
			return (free(reste), NULL);
	}

					//	bien free le buffer avant de return.
					//
					//	envoyer reste dans ft_process_line
					//	celui-ci va extraire la premiere moitie
					//	de la chaine de caractere.
					//	(du debut jusqu'au premier /n)
					//	stocker tout cela dans line.
					//
					//	et avant de return line, mettre a jour le reste
					//	en l'envoyant a ft_remaining.
					//	(garder tout ce qu'il y a apres le /n).

	free(buffer);
	line = ft_process_line(reste);
	reste = ft_remaining(reste);
	return (line);
}
