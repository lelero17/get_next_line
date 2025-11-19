/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:10:22 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/19 15:39:14 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stash(int fd, char *buffer, char *stash)
{
	int		bytes;
	char	*temp;

	while (!gnl_isnewln(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(stash), NULL);
		if (bytes == 0)
			return (stash);
		buffer[bytes] = '\0';
		temp = stash;
		stash = gnl_strjoin(stash, buffer);
		if (!stash)
			return (free(temp), NULL);
		free (temp);
	}
	return (stash);
}

char	*new_line(char *stash)
{
	size_t	i;
	size_t	len;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	len = i;
	if (stash[i] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

char	*new_vals(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	len = gnl_strlen(stash);
	new_stash = malloc((len - i));
	if (!new_stash)
		return (free(stash), NULL);
	j = 0;
	i++;
	while (i < len)
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*freeall(char **stash)
{
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (freeall(&stash));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (freeall(&stash));
	if (!stash || !gnl_isnewln(stash))
		stash = fill_stash(fd, buffer, stash);
	if (!stash)
		return (free(buffer), NULL);
	line = new_line(stash);
	if (!line)
	{
		free(buffer);
		return (freeall(&stash));
	}
	stash = new_vals(stash);
	free (buffer);
	return (line);
}
