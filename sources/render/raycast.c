/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:45:17 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/14 21:05:06 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"


void	init_step_and_side_dist(t_cast *cast)
{
	if (cast->ray_dir.x < 0)
	{
		cast->step.x = -1;
		cast->side_dist.x = (cast->pos.x - cast->map.x) * cast->delta_dist.x;
	}
	else
	{
		cast->step.x = 1;
		cast->side_dist.x = (cast->map.x - cast->pos.x + 1.0) \
		* cast->delta_dist.x;
	}
	if (cast->ray_dir.y < 0)
	{
		cast->step.y = -1;
		cast->side_dist.x = (cast->pos.y - cast->map.y) * cast->delta_dist.y;
	}
	else
	{
		cast->step.y = 1;
		cast->side_dist.y = (cast->map.y - cast->pos.y + 1.0) \
		* cast->delta_dist.y;
	}
}

void	DDA(t_cast *cast, char **map)
{
	while(cast->hit == 0)
	{
		if (cast->side_dist.x < cast->side_dist.y)
		{
			cast->side_dist.x += cast->delta_dist.x;
			cast->map.x += cast->step.x;
			cast->side = 0;
		}
		else
		{
			cast->side_dist.y += cast->delta_dist.y;
			cast->map.y += cast->step.y;
			cast->side = 1;
		}
		if (map[cast->map.x][cast->map.y] != '0')
			cast->hit = 1;
	}
}

void	draw_walls(double perp_wall_dist, )
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = 
}

void	raycast(t_data *data)
{
	t_map_info	*map_info;
	t_cast		*cast;
	int			x;
	int			y;

	map_info = data->map_info;
	cast = data->cast;
	x = 0;
	while (x < WIDTH)
	{
		//ray position & direction 계산
		cast->camera.x = 2 * x / (double)WIDTH - 1;
		cast->ray_dir.x = cast->dir.x + (cast->plane.x * cast->camera.x);
		cast->ray_dir.y = cast->dir.y + (cast->plane.y * cast->camera.x);
		set_int_vector(&cast->map, (int)cast->pos.x, (int)cast->pos.y);
		/*
			##length of ray from one x or y-side to next x or y-side##
      			double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
      			double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
		*/
		cast->hit = 0;
		init_step_and_side_dist(cast);
		DDA(cast, map_info->map);
		if (cast->side == 0)
			cast->perp_wall_dist = (cast->side_dist.x - cast->delta_dist.x);
		else
			cast->perp_wall_dist = (cast->side_dist.y - cast->delta_dist.y);
	}

}
