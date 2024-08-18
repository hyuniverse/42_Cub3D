/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:24:24 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/18 14:55:50 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

void	rotate(t_cast *cast, int sign)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	speed = sign * cast->rot_speed;
	old_dir_x = cast->dir.x;
	cast->dir.x = cast->dir.x * cos(speed) - cast->dir.y * sin(speed);
	cast->dir.y = old_dir_x * sin(speed) + cast->dir.y * cos(speed);
	old_plane_x = cast->plane.x;
	cast->plane.x = cast->plane.x * cos(speed) - cast->plane.y * sin(speed);
	cast->plane.y = old_plane_x * sin(speed) + cast->plane.y * cos(speed);
}

void	move_fb(char **map, t_cast *cast, int sign)
{
	int	new_x;
	int	new_y;

	new_x = (int)(cast->pos.x + sign * cast->dir.x * cast->move_speed);
	new_y = (int)(cast->pos.y + sign * cast->dir.y * cast->move_speed);
	if (map[(int)cast->pos.y][new_x] && map[(int)cast->pos.y][new_x] == '0')
		cast->pos.x += sign * cast->dir.x * cast->move_speed;
	if (map[new_y][(int)cast->pos.x] && map[new_y][(int)cast->pos.x] == '0')
		cast->pos.y += sign * cast->dir.y * cast->move_speed;
}

void	move_lr(char **map, t_cast *cast, int sign)
{
	int	new_x;
	int	new_y;

	new_x = (int)(cast->pos.x + sign * cast->plane.x * cast->move_speed);
	new_y = (int)(cast->pos.y + sign * cast->plane.y * cast->move_speed);
	if (map[(int)cast->pos.y][new_x] && map[(int)cast->pos.y][new_x] == '0')
		cast->pos.x += sign * cast->plane.x * cast->move_speed;
	if (map[new_y][(int)cast->pos.x] && map[new_y][(int)cast->pos.x] == '0')
		cast->pos.y += sign * cast->plane.y * cast->move_speed;
}

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(0);
	else
	{
		if (keycode == LEFT)
			rotate(data->cast, 1);
		else if (keycode == RIGHT)
			rotate(data->cast, -1);
		else if (keycode == W)
			move_fb(data->map_info->map, data->cast, 1);
		else if (keycode == S)
			move_fb(data->map_info->map, data->cast, -1);
		else if (keycode == A)
			move_lr(data->map_info->map, data->cast, -1);
		else if (keycode == D)
			move_lr(data->map_info->map, data->cast, 1);
		else
			return (0);
		draw(data, &data->mlx);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
