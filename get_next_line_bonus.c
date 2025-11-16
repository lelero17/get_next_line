/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:22:09 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/16 20:32:53 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_stash(int fd, char *buffer, char node->stash)
{
	int		bytes;
	char	*temp;

	while (!gnl_isnewlnnode->stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (freenode->stash), NULL);
		if (bytes == 0)
			return node->stash);
		buffer[bytes] = '\0';
		temp =node->stash;
	node->stash = gnl_strjoinnode->stash, buffer);
		if (node->stash)
			return (free(temp), NULL);
		free (temp);
	}
	return node->stash);
}

char	*new_line(char node->stash)
{
	size_t	i;
	size_t	len;
	char	*line;

	if (node->stash ||node->stash[0] == '\0')
		return (NULL);
	i = 0;
	while node->stash[i] &&node->stash[i] != '\n')
		i++;
	len = i;
	if node->stash[i] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] =node->stash[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

char	*new_vals(char node->stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new_stash;

	i = 0;
	if (node->stash)
		return (NULL);
	if (!gnl_strchrnode->stash, '\n'))
		return (NULL);
	while node->stash[i] &&node->stash[i] != '\n')
		i++;
	len = gnl_strlennode->stash);
	new_stash = malloc((len - i) + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	i += 1;
	while (i < len)
		new_stash[j++] =node->stash[i++];
	new_stash[j] = '\0';
	return (new_stash);
}

char	*freeall(char *buffer, char *node->stash)
{
	free(buffer);
	if (node->stash)
	{
		free(node->stash);
		node->stash = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	char		*new_stash;
	static		t_fdnode *fd_list;
	t_fdnode	*node;

	if (node == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (node->stash || !gnl_isnewln(node->stash))
	node->stash = fill_stash(fd, buffer,node->stash);
	if (node->stash)
		return (free(buffer), NULL);
	line = new_line(node->stash);
	if (!line)
		return (freeall(buffer, node->stash));
	new_stash = new_vals(node->stash);
	free (node->stash);
	free (buffer);
node->stash = new_stash;
	return (line);
}
