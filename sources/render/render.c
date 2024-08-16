/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:43:26 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/16 21:04:07 by sehyupar         ###   ########.fr       */
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
	printf("raycast\n");
	while (++x < WIDTH)
	{
		digital_differential_analyzer(cast, map_info->map, draw, x);
		printf("dda done\n");
		if (draw->side == 0)
		{
			//printf("case1\n");
			draw->perp_wall_dist = (cast->side_dist.x - cast->delta_dist.x);
			//printf("%f(side) - %f(delt) = %f(perp)\n", cast->side_dist.x, cast->delta_dist.x, draw->perp_wall_dist);
		}
		else
		{
			//printf("case2\n");
			draw->perp_wall_dist = (cast->side_dist.y - cast->delta_dist.y);
			//printf("%f(side) - %f(delt) = %f(perp)\n", cast->side_dist.x, cast->delta_dist.x, draw->perp_wall_dist);
		}
		calc_draw_vars(draw);
		//printf("calc draw vars\n");
		set_wall_dir(cast, draw);
		printf("tex_num = %d\n", draw->tex_num);
		//calc_tex_info(draw, map_info->texture, cast);
		y = draw->start - 1;
		//printf("x=%d draw -> start=%d end=%d\n", x, draw->start, draw->end);
		while (++y < draw->end)
		{
			//printf("drawing at = %d\n", draw->start);
			color = get_color(draw, map_info->texture);
			/*
			if (draw->tex_num == NORTH)
				color = 0x0afff4;//사이안
			else if (draw->tex_num == SOUTH)
				color = 0x0b0aff;//남색
			else if (draw->tex_num == WEST)
				color = 0x098718;//연두
			else if (draw->tex_num == EAST)
				color = 0xce00ce;//핑크
			else
				color = 0x000000;
			*/
			//printf("color = %x\n", color);
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
	//printf("img ptr : %p\n", data->img);
	draw(data, mlx);
	//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	//mlx_key_hook(data->win, key_hook, 0);
	mlx_hook(mlx->win, CLOSE_BTN, 0, exit_hook, 0);
	mlx_loop(mlx->mlx);
}
