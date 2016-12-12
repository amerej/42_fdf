/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:05:00 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/12 18:08:31 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_draw_in_limits(t_point *p)
{
	if (!(p->x > WIN_WIDTH - 10 || p->x < 10 || p->y > WIN_HEIGHT - 10 ||
		p->y < 10))
		return (1);
	else
		return (0);
}

void		ft_draw_point(t_env *env, t_point *p1, t_point *p2)
{
	env->data[((int)ceil(p1->y) * WIN_WIDTH) + (int)ceil(p1->x)] =
		ft_get_color(p1, p2);
}

void		ft_draw_line(t_env *env, t_draw_line d, t_point p1, t_point p2)
{
	d.delta.x = fabs(ceil(p2.x) - ceil(p1.x));
	d.delta.y = fabs(ceil(p2.y) - ceil(p1.y));
	d.step.x = (ceil(p1.x) < ceil(p2.x)) ? 1 : -1;
	d.step.y = (ceil(p1.y) < ceil(p2.y)) ? 1 : -1;
	d.err_1 = (d.delta.x > d.delta.y ? d.delta.x : -d.delta.y) / 2;
	if (!ft_draw_in_limits(&p1) && !ft_draw_in_limits(&p2))
		return ;
	while (1)
	{
		ft_draw_point(env, &p1, &p2);
		if ((int)ceil(p1.x) == (int)ceil(p2.x) && (int)ceil(p1.y) ==
			(int)ceil(p2.y))
			break ;
		d.err_2 = d.err_1;
		if (d.err_2 > -d.delta.x)
		{
			d.err_1 -= d.delta.y;
			p1.x = ceil(p1.x) + d.step.x;
		}
		if (d.err_2 < d.delta.y)
		{
			d.err_1 += d.delta.x;
			p1.y = ceil(p1.y) + d.step.y;
		}
	}
}

void		ft_draw_map(t_env *env, t_map *map)
{
	int			x;
	int			y;
	t_draw_line	d;

	y = -1;
	while (++y < map->size.y)
	{
		x = -1;
		while (++x < map->size.x)
		{
			if (x < map->size.x - 1)
				ft_draw_line(env, d, map->coord[y][x], map->coord[y][x + 1]);
			if (y < env->map->size.y - 1)
				ft_draw_line(env, d, map->coord[y][x], map->coord[y + 1][x]);
		}
	}
}

void		ft_draw_image(t_env *env)
{
	int		bpp;
	int		sizeline;
	int		endian;

	env->img_ptr = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->data = (int *)mlx_get_data_addr(env->img_ptr, &bpp, &sizeline,
		&endian);
	ft_draw_map(env, env->map);
	mlx_put_image_to_window(env->mlx, env->win, env->img_ptr, 0, 0);
	mlx_destroy_image(env->mlx, env->img_ptr);
}
