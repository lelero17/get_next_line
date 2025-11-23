/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:41:44 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/23 16:32:16 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static struct
{
	char	buf[BUFFER_SIZE];
	int		pos;
	int		len;
} s_d;

int	fill_buffer(int fd)
{
	int	bytes;

	while (gnl_nl_in_range(s_d.buf, s_d.pos, s_d.len) == -1)
	{
		if (s_d.pos > 0)
		{
			gnl_memmove(s_d.buf, s_d.buf + s_d.pos, s_d.len - s_d.pos);
			s_d.len -= s_d.pos;
			s_d.pos = 0;
		}
		else if (s_d.len >= BUFFER_SIZE)
			return (1);
		bytes = read(fd, s_d.buf + s_d.len, BUFFER_SIZE - s_d.len);
		if (bytes <= 0)
			return (bytes);
		s_d.len += bytes;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	int		fill_result;
	int		line_len;
	int		i;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_result = fill_buffer(fd);
	if (fill_result == -1 || (fill_result == 0 && s_d.pos >= s_d.len))
		return (NULL);
	line_len = 0;
	while (s_d.pos + line_len < s_d.len && s_d.buf[s_d.pos + line_len] != '\n')
		line_len++;
	if (s_d.pos + line_len < s_d.len && s_d.buf[s_d.pos + line_len] == '\n')
		line_len++;
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < line_len)
		line[i] = s_d.buf[s_d.pos + i];
	line[line_len] = '\0';
	s_d.pos += line_len;
	return (line);
}
