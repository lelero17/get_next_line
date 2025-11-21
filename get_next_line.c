/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:41:44 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/21 17:05:46 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static struct {
	char	stash[BUFFER_SIZE + 1];
	int		pos;
	int		len;
} data;

char	*get_next_line(int fd)
{
	int		fill_result;
	int		line_len;
	char	*line;
	
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_result = fill_buffer(fd);
	if(fill_result == -1 || (fill_result == 0 && data.len == 0))
		return(NULL);
	line_len = 0;
	while(data.stash[data.pos + line_len] != '\n')
		line_len++;
	line = malloc(line_len + 1);
	
	
}

int	fill_buffer(int fd)
{
	int	bytes;
	while(gnl_nl_in_range(data.stash, data.pos, data.len) == -1)
	{
		if (data.len >= BUFFER_SIZE - 1)
		{
			gnl_memmove(data.stash, data.stash + data.pos, data.len - data.pos);
			data.len -= data.pos;
			data.pos = 0;
		}
		bytes = read(fd, data.stash + data.len, BUFFER_SIZE - data.len);
		if (bytes < 0)
			return(-1);
		if (bytes == 0)
			return (0);
		data.len += bytes;
	}
	return (1);
}
