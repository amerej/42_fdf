/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:11:12 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/08 18:44:58 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_import_map(t_env *env, char *argv)
{
	env->map = (t_map *)malloc(sizeof(t_map));
	env->map->list = ft_map_get_list(argv);
	env->map->size = ft_map_get_size(env->map);
	env->map->coord = ft_map_get_coord(env->map);
	return (0);
}

int		ft_init_env(t_env *env)
{
	env = (t_env *)malloc(sizeof(t_env));
	if ((env->mlx = mlx_init()) == NULL)
		return (-1);
	if ((env->win = mlx_new_window(env->mlx,
		WIN_WIDTH, WIN_HEIGHT, "fdf 42")) == NULL)
		return (-1);
	return (0);
}

void		ft_print_coord(t_env *env)
{
	int		y = -1;
	while (++y < env->map->size.y)
	{
		int x = -1;
		while (++x < env->map->size.x)
		{
			printf("\033[31m%d,\033[32m%d,\033[34m%d ",
			env->map->coord[y][x].x, env->map->coord[y][x].y, env->map->coord[y][x].z);
		}
		printf("\n");
	}
}

int			main(int argc, char *argv[])
{
	t_env	*env;

	ft_init_env(env);
	ft_import_map(env, argv[1]);
	ft_print_coord(env);
	mlx_key_hook(env->win, ft_key_hook, env);
	ft_new_image(env);
	ft_draw_map(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img_ptr, 0, 0);
	mlx_loop(env->mlx);
	return (0);
}
