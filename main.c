/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:11:12 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/12 18:09:38 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_import_map(char *argv)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->list = ft_map_get_list(argv);
	map->size = ft_map_get_size(map);
	map->coord = ft_map_get_coord(map);
	return (map);
}

t_env	*ft_init_env(void)
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

void	ft_adapt_map(t_env *env)
{
	int		width;
	int		height;
	double	scale_factor;

	width = WIN_WIDTH / 2;
	height = WIN_HEIGHT / 2;
	(int)env->map->center.x == 0 ? env->map->center.x = 10 : env->map->center.x;
	scale_factor = (width - 600) / env->map->center.x;
	ft_translate(env, -env->map->center.x + width,
		-env->map->center.y + height, 0);
	ft_scale(env, scale_factor);
}

int		ft_get_color(t_point *p1, t_point *p2)
{
	int color;
	int z;

	if (p2->color > p1->color)
		z = p2->color;
	else
		z = p1->color;
	if (z < 0)
		color = 0x2C3E50;
	else if (z >= 0 && z < 10)
		color = 0x2ECC71;
	else if (z >= 10 && z < 20)
		color = 0x3498DB;
	else if (z >= 20 && z < 50)
		color = 0xB09F91E;
	else if (z >= 50 && z < 70)
		color = 0x8E44AD;
	else if (z >= 70)
		color = 0xE74C3C;
	else
		color = 0xE67E22;
	return (color);
}

int		main(int argc, char *argv[])
{
	t_env	*env;

	env = ft_init_env();
	env->map = ft_import_map(argv[1]);
	env->map->center = ft_get_map_center(env->map);
	ft_adapt_map(env);
	ft_draw_image(env);
	mlx_key_hook(env->win, ft_key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
