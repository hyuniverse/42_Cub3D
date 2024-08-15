/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:43:26 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/15 20:57:11 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_data *data)
{
	t_map_info	*map_info;
	int			i;
	int			j;

	map_info = data->map_info;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				my_mlx_pixel_put(data, i, j, map_info->ceiling_color);
			else
				my_mlx_pixel_put(data, i, j, map_info->floor_color);
			j++;
		}
	}
}

void	raycast(t_data *data, t_map_info *map_info, t_cast *cast, t_draw *draw)
{
	unsigned int	color;
	int				x;
	int				y;

	x = -1;
	while (++x < WIDTH)
	{
		digital_differential_analyzer(cast, map_info->map, draw, x);
		if (draw->side == 0)
			draw->perp_wall_dist = (cast->side_dist.x - cast->delta_dist.x);
		else
			draw->perp_wall_dist = (cast->side_dist.y - cast->delta_dist.y);
		calc_draw_vars(draw);
		set_wall_dir(cast, draw);
		calc_tex_info(draw, map_info->texture, cast);
		y = draw->start - 1;
		while (++y < draw->end)
		{
			color = get_color(draw, map_info->texture);
			my_mlx_pixel_put(data, y, x, color);
		}
		modify_speed(cast);
	}
}

void	draw(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_background(data);
	raycast(data, data->map_info, data->cast, data->draw);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	render(t_data *data)
{
	draw(data);
	//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, key_hook, 0);
	mlx_hook(data->win, CLOSE_BTN, 0, exit_hook, 0);
	mlx_loop(data->mlx);
}
