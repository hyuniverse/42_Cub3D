/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:40:49 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/14 20:41:04 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

void	load_xpm_textures(t_map_info *map_info)
{
	t_texture	*texture;
	int			i;

	texture = map_info->texture;
	i = 0;
	while (i < 4)
	{
		//load each textures

	}
}

t_cast	*init_cast(int x, int y, int dir)
{
	t_cast	*cast;

	cast = (t_cast *)malloc(sizeof(t_cast));
	if (!cast)
		return (0);
	set_int_vector(&cast->step, 0, 0);
	set_doub_vector(&cast->pos, (double)x, (double)y);
	if (dir == NORTH)
		set_doub_vector(&cast->dir, 0, 1);
	else if (dir == SOUTH)
		set_doub_vector(&cast->dir, 0, -1);
	else if (dir == WEST)
		set_doub_vector(&cast->dir, -1, 0);
	else if (dir == EAST)
		set_doub_vector(&cast->dir, 1, 0);
	set_doub_vector(&cast->plane, 0, 0.66);
	set_doub_vector(&cast->ray_dir, 0, 0);
	set_doub_vector(&cast->side_dist, 0, 0);
	set_doub_vector(&cast->delta_dist, 0, 0);
	cast->perp_wall_dist = 0;
	cast->time = 0;
	cast->old_time = 0;
}

t_data	*init_data(t_data *data)
{
	t_map_info	*map_info;

	map_info = data->map_info;
	//mlx
	data->mlx = mlx_init();
	//win
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	//img
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	//addr, bits_per_pixel, line_length, endian
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	// tex array
	load_xpm_textures(map_info);
	//cast
	data->cast = init_cast(map_info->user_x, map_info->user_y, \
	map_info->user_direction);
	if (!data->cast)
		return (0);
}
