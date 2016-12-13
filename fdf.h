/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:10:46 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/13 12:33:48 by aditsch          ###   ########.fr       */
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define TILE_WIDTH 20
# define TILE_HEIGHT 20

# define KEY_ESC 53

# define KEY_U 126
# define KEY_D 125
# define KEY_L 123
# define KEY_R 124

# define MOVE_U -100
# define MOVE_D 100
# define MOVE_L -100
# define MOVE_R 100

# define KEY_ROT_X_U 86
# define KEY_ROT_X_D 83
# define KEY_ROT_Y_U 87
# define KEY_ROT_Y_D 84
# define KEY_ROT_Z_U 88
# define KEY_ROT_Z_D 85

# define MOVE_ROT_X_U -M_PI / 8
# define MOVE_ROT_X_D M_PI / 8
# define MOVE_ROT_Y_U -M_PI / 8
# define MOVE_ROT_Y_D M_PI / 8
# define MOVE_ROT_Z_U -M_PI / 8
# define MOVE_ROT_Z_D M_PI / 8

# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78

# define MOVE_ZOOM_IN 1.1
# define MOVE_ZOOM_OUT 0.9

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
	double				w;
	int					color;
}						t_point;

typedef struct			s_point_i
{
	int					x;
	int					y;
}						t_point_i;

typedef struct			s_list
{
	char				*line;
	struct s_list		*next;
}						t_list;

typedef struct			s_map
{
	t_list				*list;
	t_point				**coord;
	t_point_i			size;
	t_point				center;
}						t_map;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_map				*map;
	void				*img_ptr;
	char				*data;
	int					s_line;
}						t_env;

typedef struct			s_draw_line
{
	t_point_i			p1;
	t_point_i			p2;
	t_point_i			delta;
	t_point_i			step;
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

t_env					*ft_init_env();
t_map					*ft_import_map(char *argv);
void					ft_print_coord(t_map *map);

void					ft_list_push_back(t_list **list, char *line);
t_list					*ft_map_get_list(char *argv);
int						ft_map_get_size(t_map *map);
t_point					**ft_map_get_coord(t_map *map);
t_point					ft_get_map_center(t_map *map);
void					ft_adapt_map(t_env *env);
int						ft_draw_in_limits(t_point *p);
int						ft_get_color(t_point *p1, t_point *p2);

t_matrix4				*ft_matrix_rotate_x(double alpha);
t_matrix4				*ft_matrix_rotate_y(double beta);
t_matrix4				*ft_matrix_rotate_z(double gamma);
t_matrix4				*ft_matrix_translate(int tx, int ty, int tz);
t_matrix4				*ft_matrix_scale(double s);
t_matrix4				*ft_matrix_translate(int tx, int ty, int tz);

void					ft_translate(t_env *env, double x, double y, double z);
void					ft_rotate(t_env *env, double rot, char axe);
void					ft_scale(t_env *env, double s);
void					ft_matrix_transform(t_matrix4 *m, t_map *map,
						t_point *p);
void					ft_matrix_transform_shape(t_map *map, t_matrix4 *m);

int						ft_key_hook(int keycode, t_env *env);
void					ft_key_hook_translate(int keycode, t_env *env);
void					ft_key_hook_rotate(int keycode, t_env *env);
void					ft_key_hook_scale(int keycode, t_env *env);

void					ft_draw_image(t_env *env);
void					ft_draw_point(t_env *env, t_point *p, int color);
void					ft_draw_map(t_env *env, t_map *map);
void					ft_draw_line(t_env *env, t_draw_line d, t_point p1,
						t_point p2);
#endif
