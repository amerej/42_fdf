/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:16:32 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/13 13:53:22 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		ft_get_map_center(t_map *map)
{
	t_point	p;

	p.x = (map->coord[map->size.y - 1][map->size.x - 1].x +
		map->coord[0][0].x) / 2;
	p.y = (map->coord[map->size.y - 1][map->size.x - 1].y +
		map->coord[0][0].y) / 2;
	return (p);
}

void		ft_list_push_back(t_list **list, char *line)
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

t_list		*ft_map_get_list(char *argv)
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

int			ft_map_get_size(t_map *map)
{
	char		**tmp;
	t_list		*list;
	int			max;

	list = map->list;
	map->size.x = 0;
	map->size.y = 0;
	while (list)
	{
		tmp = ft_strsplit(list->line, ' ');
		max = 0;
		while (tmp[max] != NULL)
			max++;
		if (map->size.x == 0)
			map->size.x = max;
		if (max != map->size.x)
			return (-1);
		map->size.y++;
		list = list->next;
	}
	return (0);
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
			coord[y][x].color = ft_atoi(tmp[x]);
		}
		list = list->next;
	}
	return (coord);
}
