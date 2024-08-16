/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:17:03 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/16 20:26:33 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_step_and_side_dist(t_cast *cast)
{
	//printf("pos(%f, %f) vs. map(%d, %d)\n", cast->pos.x, cast->pos.y, cast->map.x, cast->map.y);
	if (cast->ray_dir.x < 0)
	{
		cast->step.x = -1;
		cast->side_dist.x = (cast->pos.x - cast->map.x) * cast->delta_dist.x;
	}
	else if (cast->ray_dir.x > 0)
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
	else if (cast->ray_dir.y > 0)
	{
		cast->step.y = 1;
		cast->side_dist.y = (cast->map.y - cast->pos.y + 1.0) \
		* cast->delta_dist.y;
	}
}

void	init_vars_before_analyze(t_cast *cast, int x)
{
	cast->camera.x = 2 * x / (double)WIDTH - 1; //window
	cast->ray_dir.x = cast->dir.x + (cast->plane.x * cast->camera.x);
	cast->ray_dir.y = cast->dir.y + (cast->plane.y * cast->camera.x);
	set_int_vector(&cast->map, (int)cast->pos.x, (int)cast->pos.y);
	set_int_vector(&cast->step, 0, 0);
	set_doub_vector(&cast->side_dist, 0, 0);
	cast->delta_dist.x = get_delta(cast->ray_dir.x);
	cast->delta_dist.y = get_delta(cast->ray_dir.y);
	cast->hit = 0;
	init_step_and_side_dist(cast);
	//printf("x=%d, ray(%f, %f), delta(%f, %f), side(%f, %f)\n", x, cast->ray_dir.x, cast->ray_dir.y, cast->delta_dist.x, cast->delta_dist.y, cast->side_dist.x, cast->side_dist.y);
}

void	digital_differential_analyzer(t_cast *cast, char **map, t_draw *draw, \
int x)
{
	init_vars_before_analyze(cast, x);
	while (cast->hit == 0)
	{
		//printf("map: ");
		//printf("(%d, %d)\n",cast->map.x, cast->map.y);
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
		//printf("->(%d, %d)",cast->map.x, cast->map.y);
		// if (map[cast->map.x][cast->map.y] == '0')
		if (map[cast->map.y][cast->map.x] == '1')
			cast->hit = 1;
	}
	//printf("\n");
}
