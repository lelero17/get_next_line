/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:47:19 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/25 13:13:29 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *s, int len)
{
	int	i;

	while (i < len)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}


