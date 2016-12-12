/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tranform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:09:57 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/12 18:12:05 by aditsch          ###   ########.fr       */
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

t_matrix4	*ft_matrix_scale(double s)
{
	t_matrix4 *m;

	if (!(m = (t_matrix4 *)ft_memalloc(sizeof(*m))))
		exit(1);
	m->x1 = s;
	m->y2 = s;
	m->z3 = s;
	m->w4 = 1;
	return (m);
}
