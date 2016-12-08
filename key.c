/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:55:41 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/08 18:42:34 by aditsch          ###   ########.fr       */
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

int		ft_key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	ft_key_hook_translate(keycode, env);
	return (0);
}
