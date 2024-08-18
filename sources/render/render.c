/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:43:26 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/18 13:04:53 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

void	my_mlx_pixel_put(t_mlx	*mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_mlx *mlx, t_map_info *map_info)
{
	int			i;
	int			j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			if (i < HEIGHT / 2)
			{
				my_mlx_pixel_put(mlx, j, i, map_info->ceiling_color);
			}
			else
				my_mlx_pixel_put(mlx, j, i, map_info->floor_color);
		}
	}
}

void	raycast(t_mlx *mlx, t_map_info *map_info, t_cast *cast, t_draw *draw)
{
	unsigned int	color;
	int				x;
	int				y;

	x = -1;
	while (++x < WIDTH)
	{
		digital_differential_analyzer(cast, map_info, draw, x);
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
			my_mlx_pixel_put(mlx, x, y, color);
		}
		modify_speed(cast);
	}
}

void	draw(t_data *data, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_background(mlx, data->map_info);
	raycast(mlx, data->map_info, data->cast, data->draw);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	render(t_data *data, t_mlx *mlx)
{
	draw(data, mlx);
	mlx_hook(mlx->win, KEY_PRESS, 0, key_press_hook, data);
	mlx_hook(mlx->win, CLOSE_BTN, 0, exit_hook, 0);
	mlx_loop(mlx->mlx);
}
