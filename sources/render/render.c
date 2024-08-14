/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:43:26 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/14 19:46:40 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_data *data)
{
	t_map_info	*map_info;
	int			i;
	int			j;
	long		color;

	map_info = data->map_info;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				my_mlx_pixel_put(&data, i, j, map_info->ceiling_color);
			else
				my_mlx_pixel_put(&data, i, j, map_info->floor_color);
			j++;
		}
	}
}

void	draw(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_background(data);
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	render(t_data *data)
{
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, key_hook, 0);
	mlx_hook(data->win, CLOSE_BTN, 0, exit_hook, 0);
	mlx_loop(data->mlx);
}
