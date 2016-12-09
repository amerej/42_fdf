/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:42:21 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/09 17:32:16 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix4	*ft_matrix_translate(int tx, int ty, int tz)
{
	t_matrix4	*m;

	if (!(m = (t_matrix4 *)ft_memalloc(sizeof(*m))))
		exit(1);
	m->x1 = 1;
	m->x4 = tx;
	m->y2 = 1;
	m->y4 = ty;
	m->z4 = tz;
	m->z3 = 1;
	m->w4 = 1;
	return (m);
}

t_matrix4	*ft_matrix_rotate_x(double alpha)
{
	t_matrix4	*m;

	if (!(m = (t_matrix4 *)ft_memalloc(sizeof(*m))))
		exit(1);
	m->x1 = 1;
	m->y2 = cos(alpha);
	m->y3 = -sin(alpha);
	m->z2 = sin(alpha);
	m->z3 = cos(alpha);
	m->w4 = 1;
	return (m);
}

t_matrix4	*ft_matrix_rotate_y(double beta)
{
	t_matrix4	*m;

	if (!(m = (t_matrix4 *)ft_memalloc(sizeof(*m))))
		exit(1);
	m->x1 = cos(beta);
	m->x3 = sin(beta);
	m->y2 = 1;
	m->z1 = -sin(beta);
	m->z3 = cos(beta);
	m->w4 = 1;
	return (m);
}

t_matrix4	*ft_matrix_rotate_z(double gamma)
{
	t_matrix4	*m;

	if (!(m = (t_matrix4 *)ft_memalloc(sizeof(*m))))
		exit(1);
	m->x1 = cos(gamma);
	m->x2 = -sin(gamma);
	m->y1 = sin(gamma);
	m->y2 = cos(gamma);
	m->z3 = 1;
	m->w4 = 1;
	return (m);
}

void		ft_translate(t_env *env, double x, double y, double z)
{
	t_matrix4	*m;

	m = ft_matrix_translate(x, y, z);
	ft_matrix_transform_shape(env->map, m);
	env->map->center = ft_get_map_center(env->map);
	free(m);
}

void		ft_rotate(t_env *env, double rot, char axe)
{
	t_matrix4	*m;

	if (axe == 'x')
		m = ft_matrix_rotate_x(rot);
	else if (axe == 'y')
		m = ft_matrix_rotate_y(rot);
	else
		m = ft_matrix_rotate_z(rot);
	ft_matrix_transform_shape(env->map, m);
	free(m);
}

void		ft_matrix_transform(t_matrix4 *m, t_map *map, t_point *p)
{
	int		tx;
	int		ty;
	int		tz;
	p->x -= map->center.x;
	p->y -= map->center.y;
	tx = p->x * m->x1 + p->y * m->x2 + p->z * m->x3 + p->w * m->x4;
	ty = p->x * m->y1 + p->y * m->y2 + p->z * m->y3 + p->w * m->y4;
	tz = p->x * m->z1 + p->y * m->z2 + p->z * m->z3 + p->w * m->z4;
	p->x = tx;
	p->y = ty;
	p->z = tz;
	p->x += map->center.x;
	p->y += map->center.y;
}

void		ft_matrix_transform_shape(t_map *map, t_matrix4 *m)
{
	int			x;
	int			y;

	y = -1;
	while (++y < map->size.y)
	{
		x = -1;
		while (++x < map->size.x)
			ft_matrix_transform(m, map, &map->coord[y][x]);
	}
}
