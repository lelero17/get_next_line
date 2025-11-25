/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:23:30 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/25 18:25:56 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(fd)
{
	static char stash[BUFFER_SIZE + 1];
	char		*line;
	size_t		stash_len;
	int			nl_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	stash_len = 0;
	while (stash[stash_len])
		stash_len++;
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
	if (nl_pos == -1)
	{
		
	}
}
