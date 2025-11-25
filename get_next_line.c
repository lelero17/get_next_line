/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:41:44 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/25 13:22:47 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_static
{
	char	buf[BUFFER_SIZE];
	int		pos;
	int		len;
}	t_static;



char	*get_next_line(int fd)
{
	static t_static	s = {0};
	char			*line;
	int				nl_pos;
	int				bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (s.pos >= s.len)
		{
			bytes = read(fd, s.buf, BUFFER_SIZE);
			if (bytes <= 0)
			{
				if(bytes < 0 || line == NULL)
				{
					free (line);
					return(NULL);
				}
				return(line);
			}
			s.len = bytes;
			s.pos = 0;
		}
		nl_pos = find_nl(s.buf + s.pos, s.len - s.pos);
		if (nl_pos != -1)
		{
			line = new_line(line, s.buf + s.pos, nl_pos + 1);
			s.pos += nl_pos + 1;
			return (line);
		}
		line = new_line(line, s.buf + s.pos, s.len - s.pos);
		s.pos = s.len;
	}
	
}
