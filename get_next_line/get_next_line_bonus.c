/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:03:52 by nlenoch           #+#    #+#             */
/*   Updated: 2021/09/23 14:15:58 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_newline(char **st, char **line)
{
	char	*pos;
	char	*tmp;

	pos = ft_strchr(*st, '\n');
	if (pos == NULL)
	{
		if ((*st)[0] == '\0')
		{
			free(*st);
			*line = NULL;
		}
		else
			*line = *st;
		*st = NULL;
	}
	else
	{
		*line = ft_substr(*st, 0, (pos - (*st)) + 1);
		if (pos[1] == '\0')
			tmp = NULL;
		else
			tmp = ft_strdup(pos + 1);
		free(*st);
		*st = tmp;
	}
}

char	*get_next_line(int fd)
{
	int			rd;
	static char	*st[MAX_FDS];
	char		*tmp;
	char		*buff;
	char		*line;

	if (st[fd] == NULL)
		st[fd] = ft_strdup("");
	buff = malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (buff == NULL)
		return (NULL);
	while (ft_strchr(st[fd], '\n') == NULL)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		tmp = st[fd];
		st[fd] = ft_strjoin(st[fd], buff);
		free(tmp);
	}
	ft_newline(&st[fd], &line);
	free(buff);
	return (line);
}
