/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:23:30 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/26 18:18:17 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	size_t		stash_len;
	int			nl_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash_len = gnl_strlen(stash);
	nl_pos = gnl_find_nl(stash, stash_len);
	if (nl_pos >= 0)
	{
		line = gnl_nl_in_stash(stash, nl_pos, stash_len);
		if (!line)
			return (NULL);
		return (line);
	}
	line = NULL;
	nl_pos = gnl_read_until_nl(fd, stash, &line, &stash_len);
	if (nl_pos == -2)
		return (free(line), NULL);
	return (gnl_finalize_line(&line, stash, nl_pos, stash_len));
}

char	*gnl_nl_in_stash(char *stash, int nl_pos, size_t stash_len)
{
	char	*line;

	line = malloc(nl_pos + 2);
	if (!line)
		return (NULL);
	gnl_memcpy(line, stash, nl_pos + 1);
	line[nl_pos + 1] = '\0';
	gnl_memmove(stash, &stash[nl_pos + 1], stash_len - (nl_pos + 1));
	stash[stash_len - (nl_pos + 1)] = '\0';
	return (line);
}

int	gnl_read_until_nl(int fd, char *stash, char **line, size_t *stash_len)
{
	int	nl_pos;
	int	bytes;

	while (1)
	{
		if (*stash_len > 0)
		{
			nl_pos = gnl_find_nl(stash, *stash_len);
			if (nl_pos >= 0)
				return (nl_pos);
			if (!gnl_append_to_line(line, stash, *stash_len))
				return (-2);
			*stash_len = 0;
		}
		bytes = read(fd, stash, BUFFER_SIZE);
		if (bytes < 0)
			return (gnl_clean_stash(stash, stash_len, -2));
		if (bytes == 0)
			return (gnl_clean_stash(stash, stash_len, -1));
		stash[bytes] = '\0';
		*stash_len = bytes;
	}
}

char	*gnl_finalize_line(char **line, char *stash, int nl_pos, size_t stash_len)
{
	if (nl_pos >= 0)
	{
		if (!gnl_append_to_line(line, stash, nl_pos + 1))
			return (free(*line), NULL);
		gnl_memmove(stash, stash + nl_pos + 1, stash_len - (nl_pos + 1));
		stash[stash_len - (nl_pos + 1)] = '\0';
		return (*line);
	}
	if (stash_len > 0)
	{
		if (!gnl_append_to_line(line, stash, stash_len))
			return (free(*line), NULL);
		stash[0] = '\0';
		return (*line);
	}
	return (*line);
}

int	gnl_clean_stash(char *stash, size_t *stash_len, int ret_val)
{
	stash[0] = '\0';
	*stash_len = 0;
	return (ret_val);
}
