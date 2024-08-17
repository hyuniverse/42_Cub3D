/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:45:17 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/17 19:40:38 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

void	set_wall_dir(t_cast *cast, t_draw *draw)
{
	if (draw->side == 0)
		draw->tex_num = get_dir(cast->ray_dir.x, 'x', 1);
	else
		draw->tex_num = get_dir(cast->ray_dir.y, 'y', 1);
}

void	calc_draw_vars(t_draw *draw)
{
	draw->line_height = (int)(HEIGHT / draw->perp_wall_dist);
	draw->start = (HEIGHT - draw->line_height) / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = (HEIGHT + draw->line_height) / 2;
	if (draw->end >= HEIGHT)
		draw->end = HEIGHT - 1;
}

void	calc_tex_info(t_draw *draw, t_texture *texture, t_cast *cast)
{
	int	width;
	int	height;

	width = texture[draw->tex_num].width;
	height = texture[draw->tex_num].height;
	if (draw->side == 0)
		draw->wall_x = cast->pos.y + (draw->perp_wall_dist * cast->ray_dir.y);
	else
		draw->wall_x = cast->pos.x + (draw->perp_wall_dist * cast->ray_dir.x);
	draw->wall_x -= (int)draw->wall_x;
	draw->tex.x = (int)(draw->wall_x * (double)width);
	if ((draw->side == 0 && cast->ray_dir.x > 0) || \
	(draw->side == 1 && cast->ray_dir.y < 0))
		draw->tex.x = width - draw->tex.x - 1;
	draw->step = (double)height / draw->line_height;
	draw->tex_pos = (draw->start + (draw->line_height - HEIGHT) / 2) \
	* draw->step;
}

unsigned int	get_color(t_draw *draw, t_texture *texture)
{
	unsigned int	color;
	int				idx;
	int				width;
	int				height;

	idx = draw->tex_num;
	width = texture[idx].width;
	height = texture[idx].height;
	draw->tex.y = (int)draw->tex_pos;
	draw->tex_pos += draw->step;
	color = texture[idx].data[width * draw->tex.y + draw->tex.x];
	if (draw->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

void	modify_speed(t_cast *cast)
{
	double	frame_time;

	cast->old_time = cast->time;
	cast->time = get_time();
	frame_time = cast->time - cast->old_time;
	cast->move_speed = frame_time * 5.0 / 50;
	cast->rot_speed = frame_time * 3.0 / 50;
}
