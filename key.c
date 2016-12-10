/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:55:41 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/10 15:20:28 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_hook_translate(int keycode, t_env *env)
{
	if (keycode == KEY_U)
		ft_translate(env, 0, MOVE_U, 0);
	else if (keycode == KEY_D)
		ft_translate(env, 0, MOVE_D, 0);
	else if (keycode == KEY_L)
		ft_translate(env, MOVE_L, 0, 0);
	else if (keycode == KEY_R)
		ft_translate(env, MOVE_R, 0, 0);
}

void	ft_key_hook_rotate(int keycode, t_env *env)
{
	if (keycode == KEY_ROT_X_U)
		ft_rotate(env, MOVE_ROT_X_U, 'x');
	else if (keycode == KEY_ROT_X_D)
		ft_rotate(env, MOVE_ROT_X_D, 'x');
	else if (keycode == KEY_ROT_Y_U)
		ft_rotate(env, MOVE_ROT_Y_U, 'y');
	else if (keycode == KEY_ROT_Y_D)
		ft_rotate(env, MOVE_ROT_Y_D, 'y');
	else if (keycode == KEY_ROT_Z_U)
		ft_rotate(env, MOVE_ROT_Z_U, 'z');
	else if (keycode == KEY_ROT_Z_D)
		ft_rotate(env, MOVE_ROT_Z_D, 'z');
}

int		ft_key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	ft_key_hook_translate(keycode, env);
	ft_key_hook_rotate(keycode, env);
	ft_print_coord(env->map);
	ft_draw_image(env);
	return (0);
}
