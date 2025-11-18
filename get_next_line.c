/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:10:22 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/18 18:38:50 by lemmerli         ###   ########.fr       */
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

	i = 0;
	if (!stash)
		return (NULL);
	if (!gnl_strchr(stash, '\n'))
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	len = gnl_strlen(stash);
	new_stash = malloc((len - i) + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	i += 1;
	while (i < len)
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (new_stash);
}

char	*freeall(char **buffer, char **stash)
{
	free(*buffer);
	*buffer = NULL;
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
	char		*new_stash;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stash || !gnl_isnewln(stash))
		stash = fill_stash(fd, buffer, stash);
	if (!stash)
		return (free(buffer), NULL);
	line = new_line(stash);
	if (!line)
		return (freeall(&buffer, &stash));
	new_stash = new_vals(stash);
	free (stash);
	free (buffer);
	stash = new_stash;
	return (line);
}
