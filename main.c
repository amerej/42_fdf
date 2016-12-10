/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:11:12 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/10 15:20:38 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		*ft_import_map(char *argv)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->list = ft_map_get_list(argv);
	map->size = ft_map_get_size(map);
	map->coord = ft_map_get_coord(map);
	return (map);
}

t_env		*ft_init_env()
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if ((env->mlx = mlx_init()) == NULL)
		return (NULL);
	if ((env->win = mlx_new_window(env->mlx,
		WIN_WIDTH, WIN_HEIGHT, "fdf 42")) == NULL)
		return (NULL);
	return (env);
}

void		ft_print_coord(t_map *map)
{
	int		y = -1;
	while (++y < map->size.y)
	{
		int x = -1;
		while (++x < map->size.x)
			printf("\033[31m%lf,\033[32m%lf,\033[34m%lf ",
			map->coord[y][x].x, map->coord[y][x].y, map->coord[y][x].z);
		printf("\n");
	}
}

int			main(int argc, char *argv[])
{
	t_env	*env;

	env = ft_init_env();
	env->map = ft_import_map(argv[1]);
	ft_print_coord(env->map);
	env->map->center = ft_get_map_center(env->map);
	ft_draw_image(env);
	mlx_key_hook(env->win, ft_key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
