/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:23:30 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/25 20:10:37 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(fd)
{
	static char stash[BUFFER_SIZE + 1];
	char		*line;
	size_t		stash_len;
	int			nl_pos;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash_len = gnl_strlen(stash);
	nl_pos = gnl_find_nl(stash, stash_len);
	if (nl_pos >= 0)
	{
		line = malloc(nl_pos + 2);
		if (!line)
			return (NULL);
		gnl_memcpy(line, stash, nl_pos + 1);
		line[nl_pos + 1] = '\0';
		gnl_memmove(stash, &stash[nl_pos + 1], stash_len - (nl_pos + 1));
		stash[stash_len - (nl_pos + 1)] = '\0';
	}
	while (1)
	{
		if(stash_len > 0)
		{
			if(!gnl_append_to_line(&line, stash, stash_len))
				return (free(line), NULL);
			stash[0] = '\0';
			stash_len = 0;
		}
		bytes = read(fd, stash, BUFFER_SIZE);
		if (bytes < 0)
			return(free(line), NULL);
		if (bytes == 0)
			break;
		stash[bytes] = '\0';
		stash_len = bytes;
		nl_pos = gnl_find_nl(stash, stash_len);
		if (nl_pos >= 0)
			break;
	}
	if (nl_pos >= 0)
	{
		gnl_append_to_line(*line, stash, stash_len - (nl_pos + 1));
		gnl_memmove(stash, &stash[nl_pos + 1], stash_len - (nl_pos + 1));
		stash[stash_len - (nl_pos + 1)] = '\0';
	}
}
