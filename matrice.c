/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:42:21 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/08 18:39:12 by aditsch          ###   ########.fr       */
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

void		ft_translate(t_env *env, double x, double y, double z)
{
	t_matrix4	*m;

	m = ft_matrix_translate(x, y, z);
	ft_matrix_transform_shape(env->map, m);
	free(m);
}

void		ft_matrix_transform(t_matrix4 *m, t_point *p)
{
	int		tx;
	int		ty;
	int		tz;
	tx = (int) (p->x * m->x1 + p->y * m->x2 + p->z * m->x3 + p->w * m->x4);
	ty = (int) (p->x * m->y1 + p->y * m->y2 + p->z * m->y3 + p->w * m->y4);
	tz = (int) (p->x * m->z1 + p->y * m->z2 + p->z * m->z3 + p->w * m->z4);
	p->x = tx;
	p->y = ty;
	p->z = tz;
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
			ft_matrix_transform(m, &map->coord[y][x]);
	}
}
