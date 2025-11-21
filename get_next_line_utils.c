/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:47:19 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/21 16:51:43 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int gnl_nl_in_range(char *s, int start, int len)
{
	int	i;

	i = start;
	while(i < len)
	{
		if(s[i] == '\n')
			return(i);
		i++;
	}
	return(-1);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
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