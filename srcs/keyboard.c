/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:30:01 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 21:30:02 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward_and_back(t_all *all, int keycode)
{
	if (keycode == FORWARD)
	{
		if (no_clip(all, 1))
		{
			all->ray.px += all->ray.pdx * 0.3;
			all->ray.py += all->ray.pdy * 0.3;
		}
	}
	if (keycode == BACK)
	{
		if (no_clip(all, 2))
		{
			all->ray.px -= all->ray.pdx * 0.3;
			all->ray.py -= all->ray.pdy * 0.3;
		}
	}
}

void	move_left_and_right(t_all *all, int keycode)
{
	if (keycode == LEFT && no_clip(all, 3))
	{
		all->ray.px += all->ray.pdy * 0.1;
		all->ray.py -= all->ray.pdx * 0.1;
	}
	if (keycode == RIGHT && no_clip(all, 4))
	{
		all->ray.px -= all->ray.pdy * 0.1;
		all->ray.py += all->ray.pdx * 0.1;
	}
}

void	move_rotate(t_all *all, int keycode)
{
	if (keycode == ROTATE_LEFT)
	{
		all->ray.pa -= (M_PI) / 60;
		all->ray.pa = fix_ang(all->ray.pa);
		all->ray.pdx = cos(all->ray.pa);
		all->ray.pdy = sin(all->ray.pa);
	}
	if (keycode == ROTATE_RIGHT)
	{
		all->ray.pa += (M_PI) / 60;
		all->ray.pa = fix_ang(all->ray.pa);
		all->ray.pdx = cos(all->ray.pa);
		all->ray.pdy = sin(all->ray.pa);
	}
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == FORWARD || keycode == BACK)
		move_forward_and_back(all, keycode);
	if (keycode == LEFT || keycode == RIGHT)
		move_left_and_right(all, keycode);
	if (keycode == ROTATE_LEFT || keycode == ROTATE_RIGHT)
		move_rotate(all, keycode);
	if (keycode == M)
	{
		if (!all->minimap_flag)
			all->minimap_flag = 1;
		else
		{
			all->minimap_flag = 0;
			mlx_clear_window(all->win.mlx, all->win.mlx_win);
		}
	}
	if (keycode == ESC)
		exit(0);
	draw(all);
	if (all->minimap_flag)
		init_map_to_buffer(all);
	mlx_destroy_image(all->win.mlx, all->win.img);
	new_image(all);
	return (0);
}
