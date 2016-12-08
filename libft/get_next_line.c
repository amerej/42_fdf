/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 01:55:22 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/27 01:35:22 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd		*ft_manage_fd(t_fd **list, int fd)
{
	while (*list && (*list)->fd != fd)
		list = &(*list)->next;
	if (!*list)
	{
		*list = (t_fd *)malloc(sizeof(**list));
		(*list)->tmp = NULL;
		(*list)->fd = fd;
		(*list)->next = NULL;
	}
	return (*list);
}

int			ft_read_tmp(char **line, t_fd *list)
{
	char	*tmp;

	if (!list->tmp)
		return (0);
	if ((tmp = ft_strchr(list->tmp, '\n')))
	{
		*line = ft_strjoin(*line, ft_strsub(list->tmp, 0, tmp - list->tmp));
		list->tmp = ft_strdup(list->tmp + (tmp - list->tmp) + 1);
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, list->tmp);
		ft_strdel(&(list->tmp));
	}
	return (0);
}

int			ft_read_fd(char **line, t_fd *list)
{
	int		count;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	while ((count = read(list->fd, buffer, BUFF_SIZE)))
	{
		if (count == -1)
			return (-1);
		buffer[count] = '\0';
		if ((tmp = ft_strchr(buffer, '\n')))
		{
			*line = ft_strjoin(*line, ft_strsub(buffer, 0, tmp - buffer));
			list->tmp = ft_strdup(buffer + (tmp - buffer) + 1);
			return (1);
		}
		else
			*line = ft_strjoin(*line, buffer);
	}
	if (count == 0 && **line == '\0')
		return (0);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static t_fd		*list = NULL;
	t_fd			*current_fd;

	if (!line || fd < 0)
		return (-1);
	if (*line)
		*line = NULL;
	*line = ft_strdup("");
	current_fd = ft_manage_fd(&list, fd);
	if (ft_read_tmp(line, current_fd))
		return (1);
	return (ft_read_fd(line, current_fd));
}
