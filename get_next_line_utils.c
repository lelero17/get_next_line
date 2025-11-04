/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:10:37 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/04 19:56:25 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])	
		len++;
	return (len);
}

char	*strchr(char *s, int c)
{
	size_t			i;
	unsigned char	val;

	i = 0;
	val = (unsigned char) c;
	while (s[i])
	{
		if (val == (unsigned char)s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (val == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
