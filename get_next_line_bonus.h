/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:56:07 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/19 18:35:49 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*new_vals(char *stash);
char	*new_line(char *stash);
char	*fill_stash(int fd, char *buffer, char *stash);
char	*freeall(char **stash);

size_t	gnl_strlen(const char *s);
size_t	gnl_isnewln(const char *s);
char	*gnl_strjoin(char const *s1, char const *s2);

#endif