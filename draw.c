/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:05:00 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/09 17:26:23 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_line(t_env *env, t_point p1, t_point p2, int color)
{
	t_draw_line	d;
	d.delta.x = p2.x - p1.x < 0 ? -(p2.x - p1.x) : p2.x - p1.x;
	d.delta.y = p2.y - p1.y < 0 ? -(p2.y - p1.y) : p2.y - p1.y;
	d.step.x = (p1.x < p2.x) ? 1 : -1;
	d.step.y = (p1.y < p2.y) ? 1 : -1;
	d.err_1 = (d.delta.x > d.delta.y ? d.delta.x : -d.delta.y) / 2;
	while(1)
	{
		env->data[p1.y * WIN_WIDTH + p1.x] = color;
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		d.err_2 = d.err_1;
		if (d.err_2 > -d.delta.x)
		{
			d.err_1 -= d.delta.y;
			p1.x += d.step.x;
		}
		if (d.err_2 < d.delta.y)
		{
			d.err_1 += d.delta.x;
			p1.y += d.step.y;
		}
	}
}

void		ft_draw_map(t_env *env, t_map *map)
{
	int			x;
	int			y;

	y = -1;
	while (++y < map->size.y)
	{
		x = -1;
		while (++x < map->size.x)
		{
			if (x < map->size.x - 1)
				ft_draw_line(env, map->coord[y][x], map->coord[y][x + 1], 0x00355C7D);
			if (y < env->map->size.y - 1)
				ft_draw_line(env, map->coord[y][x], map->coord[y + 1][x], 0x00355C7D);
		}
	}
}

void		ft_draw_image(t_env *env)
{
	int		bpp;
	int		sizeline;
	int		endian;

	env->img_ptr = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->data = (int *)mlx_get_data_addr(env->img_ptr, &bpp, &sizeline, &endian);
	ft_draw_map(env, env->map);
	mlx_put_image_to_window(env->mlx, env->win, env->img_ptr, 0, 0);
	mlx_destroy_image(env->mlx, env->img_ptr);
}
