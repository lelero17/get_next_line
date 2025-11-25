/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:41:55 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/25 19:50:21 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);


size_t	gnl_strlen(char *s);
int		gnl_find_nl(const char *s, size_t stash_len);
char	*gnl_memcpy(char *dest, const char *src, size_t n);
char	*gnl_memmove(void *dest, const void *src, size_t n);
int 	gnl_append_to_line(char **line, char *data, size_t len);

#endif