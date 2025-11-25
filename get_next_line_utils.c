/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:52:15 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/25 17:17:03 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_find_nl(const char *s, size_t stash_len)
{
	size_t	i;

	if (!s)
		return (0);
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
	size_t				i;
	unsigned char		*byte_dest;
	const unsigned char	*byte_src;

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

char	*gnl_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*byte_dest;
	const unsigned char	*byte_src;

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
