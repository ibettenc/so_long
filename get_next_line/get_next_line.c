/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:13:12 by ibettenc          #+#    #+#             */
/*   Updated: 2025/07/12 15:42:29 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_stash(char **stash)
{
	if (!stash || !*stash)
		return ;
	free(*stash);
	*stash = NULL;
}

static char	*stash_read(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;

	bytes = 1;
	while (!gnl_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free_stash(&stash), NULL);
		buffer[bytes] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	size_t		i;
	size_t		len;
	char		*line;

	i = 0;
	len = 0;
	if (!stash[len])
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	size_t	start;
	char	*new_stash;
	int		len;
	int		i;

	if (!stash)
		return (NULL);
	start = 0;
	i = 0;
	while (stash[start] && stash[start] != '\n')
		start++;
	if (!stash[start])
		return (free(stash), NULL);
	start++;
	len = ft_strlen((stash) + start);
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (free(stash), NULL);
	while (stash[start])
		new_stash[i++] = stash[start++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = stash_read(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free_stash(&stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}

// #include <stdio.h>
// int		main()
// {
// 	int		i = 1;
// 	int		fd = open("test.txt", O_RDONLY);
// 	char	*line;

// 	if (fd < 0)
// 	{
// 		write(1, "opening error", 14); // affiche l'erreur si open échoue
// 		return (1);
// 	}
//  //	printf("Fichier ouvert, fd = %d\n", fd); // debug

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%d: %s", i, line); // debug
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }