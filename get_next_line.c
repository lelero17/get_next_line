/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:10:22 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/08 11:42:51 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stash(int fd, char *buffer, char *stash)
{
	int		bytes;
	char	*temp;

	while (!ft_isnewln(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(stash), NULL);
		else if (bytes == 0)
			break ;
		else
			buffer[bytes] = '\0';
		if (stash == NULL)
		{
			stash = malloc(1);
			if (!stash)
				return (NULL);
			stash[0] = '\0';
		}
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		free (temp);
	}
	return (stash);
}

char	*new_line(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*line;

	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	len = i;
	if (stash[i] == '\n')
		len++;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		line[j] = stash[j];
		j++;
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
	if (stash == NULL)
		return (NULL);
	if (ft_strchr(stash, '\n') == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	len = ft_strlen(stash);
	new_stash = malloc((len - i) + 1);
	if (new_stash == NULL)
		return (NULL);
	j = 0;
	i += 1;
	while (i < len)
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (new_stash);
}

char	*freeall(char *buffer, char **stash)
{
	free(buffer);
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
	if (buffer == NULL)
		return (NULL);
	if (stash == NULL || !ft_isnewln(stash))
		stash = fill_stash(fd, buffer, stash);
	if (stash == NULL)
		return (free(buffer), NULL);
	line = new_line(stash);
	if (line == NULL)
		return (freeall(buffer, &stash));
	new_stash = new_vals(stash);
	free (stash);
	free (buffer);
	stash = new_stash;
	return (line);
}
