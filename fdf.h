/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:10:46 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/08 18:38:16 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx_osx/mlx.h"
# include <math.h>

# define WIN_WIDTH 		800
# define WIN_HEIGHT 	600
# define TILE_WIDTH		32
# define TILE_HEIGHT 	32

# define KEY_ESC 		53

# define KEY_U 126
# define KEY_D 125
# define KEY_L 123
# define KEY_R 124

# define MOVE_U -10
# define MOVE_D 10
# define MOVE_L -10
# define MOVE_R 10

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					w;
}						t_point;

typedef struct			s_list
{
	char				*line;
	struct s_list		*next;
}						t_list;

typedef struct			s_map
{
	t_list				*list;
	t_point				**coord;
	t_point				size;
}						t_map;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_map				*map;
	void				*img_ptr;
	int					*data;
}						t_env;

typedef struct			s_draw_line
{
	t_point				p1;
	t_point				p2;
	t_point				delta;
	t_point				step;
	int					err_1;
	int					err_2;
}						t_draw_line;

typedef struct			s_matrix4
{
	double				x1;
	double				x2;
	double				x3;
	double				x4;
	double				y1;
	double				y2;
	double				y3;
	double				y4;
	double				z1;
	double				z2;
	double				z3;
	double				z4;
	double				w1;
	double				w2;
	double				w3;
	double				w4;
}						t_matrix4;

t_matrix4				*ft_matrix_rotate_x(double alpha);
t_matrix4				*ft_matrix_rotate_y(double beta);
t_matrix4				*ft_matrix_rotate_z(double gamma);
t_matrix4				*ft_matrix_translate(int tx, int ty, int tz);
t_matrix4				*ft_matrix_scale(double s);

int						ft_import_map(t_env *env, char *argv);
void					ft_list_push_back(t_list **list, char *line);
t_list					*ft_map_get_list(char *argv);
t_point					ft_map_get_size(t_map *map);
t_point					**ft_map_get_coord(t_map *map);

int						ft_init_env(t_env *env);

int						ft_key_hook(int keycode, t_env *env);

void					ft_new_image(t_env *env);
void					ft_draw_map(t_env *env);
void					ft_draw_line(t_env *env, t_point p1, t_point p2, int color);

t_matrix4				*ft_matrix_translate(int tx, int ty, int tz);
void					ft_translate(t_env *env, double x, double y, double z);
void					ft_matrix_transform(t_matrix4 *m, t_point *p);
void					ft_matrix_transform_shape(t_map *map, t_matrix4 *m);
#endif
