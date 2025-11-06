/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:10:22 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/06 19:08:45 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stash(int fd, char *buffer, char *stash)
{
	size_t	bytes;
	
	while (!ft_isnewln(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return(NULL);
		else if(bytes == 0)
			{
				break ;
			}
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*new_line(char *line, char *stash)
{
	size_t	i;

	i = 0;
	if(ft_isnewln(stash) == 0)
	{
		line = malloc(ft_strlen(stash) + 1);
		if (line == NULL)
			return (NULL);
		while (i < ft_strlen(stash))
		{
			line[i] = stash[i];
			i++;
		}
		return(line);
	}
}

char	*new_vals(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\n')
		i++;
	new_stash = malloc((ft_strlen(stash) - i) * sizeof(char));
	j = 0;
	i += 1;
	while (i <= ft_strlen(stash))
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (new_stash);
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
		return (NULL);
	line = new_line(line, stash);
	new_stash = new_vals(stash);
	free(stash);
	free (buffer);
	stash = new_stash;
	return(line);
}
