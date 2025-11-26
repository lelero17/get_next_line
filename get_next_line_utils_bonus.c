/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:29:36 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/26 18:35:08 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	gnl_find_nl(const char *s, size_t stash_len)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (i < stash_len)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_memcpy(char *dest, const char *src, size_t n)
{
	size_t		i;
	char		*byte_dest;
	const char	*byte_src;

	if (dest == 0 && src == 0)
		return (dest);
	i = 0;
	byte_dest = dest;
	byte_src = src;
	while (i < n)
	{
		byte_dest[i] = byte_src[i];
		i++;
	}
	return (dest);
}

char	*gnl_memmove(char *dest, const char *src, size_t n)
{
	size_t		i;
	char		*byte_dest;
	const char	*byte_src;

	i = 0;
	byte_dest = dest;
	byte_src = src;
	if (n == 0 || byte_dest == byte_src)
		return (dest);
	if (byte_dest < byte_src || byte_dest >= byte_src + n)
	{
		while (i < n)
		{
			byte_dest[i] = byte_src[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i > 0)
	{
		byte_dest[i - 1] = byte_src[i - 1];
		i--;
	}
	return (dest);
}

int	gnl_append_to_line(char **line, char *data, size_t len)
{
	size_t	old_len;
	char	*new_line;

	old_len = gnl_strlen(*line);
	new_line = malloc(old_len + len + 1);
	if (!new_line)
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	if (old_len > 0)
		gnl_memcpy(new_line, *line, old_len);
	gnl_memcpy(new_line + old_len, data, len);
	new_line[old_len + len] = '\0';
	free(*line);
	*line = new_line;
	return (1);
}
