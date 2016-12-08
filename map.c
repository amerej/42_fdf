/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:16:32 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/08 18:46:29 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_list_push_back(t_list **list, char *line)
{
	while (*list)
		list = &(*list)->next;
	if (!*list)
	{
		*list = (t_list *)malloc(sizeof(**list));
		(*list)->line = line;
		(*list)->next = NULL;
	}
}

t_list			*ft_map_get_list(char *argv)
{
	char	*line;
	int		fd;
	int		count;
	t_list	*list;

	list = NULL;
	fd = open(argv, O_RDONLY);
	while ((count = get_next_line(fd, &line)))
		ft_list_push_back(&list, line);
	close(fd);
	return (list);
}

t_point		ft_map_get_size(t_map *map)
{
	char		**tmp;
	t_point		p;
	t_list		*list;

	list = map->list;
	p.x = 0;
	p.y = 0;
	while (list)
	{
		if (p.x == 0)
		{
			tmp = ft_strsplit(list->line, ' ');
			while (tmp[p.x] != NULL)
				p.x++;
		}
		p.y++;
		list = list->next;
	}
	return (p);
}

t_point		**ft_map_get_coord(t_map *map)
{
	int			x;
	int			y;
	char		**tmp;
	t_point		**coord;
	t_list		*list;

	list = map->list;
	y = -1;
	coord = (t_point **)malloc(sizeof(t_point *) * map->size.y);
	while (++y < map->size.y)
	{
		coord[y] = (t_point *)malloc(sizeof(t_point) * map->size.x);
		tmp = ft_strsplit(list->line, ' ');
		x = -1;
		while (++x < map->size.x)
		{
			coord[y][x].x = x * TILE_WIDTH;
			coord[y][x].y = y * TILE_HEIGHT;
			coord[y][x].z = ft_atoi(tmp[x]);
			coord[y][x].w = 1;
		}
		list = list->next;
	}
	return (coord);
}
