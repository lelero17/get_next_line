/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:10:57 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/07 15:41:10 by lemmerli         ###   ########.fr       */
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

char	*new_vals(char *stash);
char	*new_line(char *stash);
char	*fill_stash(int fd, char *buffer, char *stash);

size_t	ft_strlen(const char *s);
char	*strchr(char *s, int c);
size_t	ft_isnewln(const char *s);

#endif