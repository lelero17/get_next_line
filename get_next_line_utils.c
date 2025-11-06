/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:10:37 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/06 15:18:18 by lemmerli         ###   ########.fr       */
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

size_t	ft_isnewln(const char *s)
{
	size_t	i;

	i = 0;
	while(s)
	{
		if (s[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*res;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc((len1 + len2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	return (res);
}