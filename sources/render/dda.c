/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:17:03 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/23 13:01:04 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
		cast->side_dist.y = (cast->pos.y - cast->map.y) * cast->delta_dist.y;
	}
	else
	{
		cast->step.y = 1;
		cast->side_dist.y = (cast->map.y - cast->pos.y + 1.0) \
		* cast->delta_dist.y;
	}
}

void	init_vars_before_analyze(t_cast *cast, int x)
{
	cast->camera.x = 2 * x / (double)WIDTH - 1;
	cast->ray_dir.x = cast->dir.x + (cast->plane.x * cast->camera.x);
	cast->ray_dir.y = cast->dir.y + (cast->plane.y * cast->camera.x);
	set_int_vector(&cast->map, (int)cast->pos.x, (int)cast->pos.y);
	set_int_vector(&cast->step, 0, 0);
	set_doub_vector(&cast->side_dist, 0, 0);
	cast->delta_dist.x = get_delta(cast->ray_dir.x);
	cast->delta_dist.y = get_delta(cast->ray_dir.y);
	cast->hit = 0;
	init_step_and_side_dist(cast);
}

void	dda(t_cast *cast, t_map_info *map, \
t_draw *draw, int x)
{
	init_vars_before_analyze(cast, x);
	while (cast->hit == 0)
	{
		if (cast->side_dist.x < cast->side_dist.y)
		{
			cast->side_dist.x += cast->delta_dist.x;
			cast->map.x += cast->step.x;
			draw->side = 0;
		}
		else
		{
			cast->side_dist.y += cast->delta_dist.y;
			cast->map.y += cast->step.y;
			draw->side = 1;
		}
		if (cast->map.x < 0 || cast->map.x >= map->map_width || \
		cast->map.y < 0 || cast->map.y >= map->map_height || \
		map->map[cast->map.y][cast->map.x] == '1')
			cast->hit = 1;
	}
}
