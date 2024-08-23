/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:40:49 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/23 17:35:40 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

unsigned int	*get_img_data(t_mlx *mlx, t_texture *tex, int idx)
{
	int				i;
	int				j;
	unsigned int	*result;
	unsigned int	*tmp;

	mlx->img = mlx_xpm_file_to_image(mlx->mlx, tex[idx].path, \
	&tex[idx].width, &tex[idx].height);
	if (!mlx->img)
		print_error("Error");
	tmp = (unsigned int *)mlx_get_data_addr(mlx->img, &mlx->bpp, \
	&mlx->line_length, &mlx->endian);
	result = (unsigned int *)malloc(sizeof(unsigned int) * \
	tex[idx].width * tex[idx].height);
	if (!result)
		print_error("Error");
	i = -1;
	while (++i < tex[idx].height)
	{
		j = -1;
		while (++j < tex[idx].width)
			result[tex[idx].width * i + j] = tmp[tex[idx].width * i + j];
	}
	mlx_destroy_image(mlx->mlx, mlx->img);
	return (result);
}

void	load_xpm_textures(t_map_info *map_info, t_mlx *mlx)
{
	t_texture	*texture;
	int			i;

	texture = map_info->texture;
	i = -1;
	while (++i < 4)
	{
		texture[i].data = get_img_data(mlx, texture, i);
		if (!texture[i].data)
			print_error("Error");
	}
}

void	init_dir_plane_vec(t_cast *cast, int dir)
{
	if (dir == NORTH)
	{
		set_doub_vector(&cast->dir, 0, -1);
		set_doub_vector(&cast->plane, 0.66, 0);
	}
	else if (dir == SOUTH)
	{
		set_doub_vector(&cast->dir, 0, 1);
		set_doub_vector(&cast->plane, -0.66, 0);
	}
	else if (dir == WEST)
	{
		set_doub_vector(&cast->dir, -1, 0);
		set_doub_vector(&cast->plane, 0, -0.66);
	}
	else if (dir == EAST)
	{
		set_doub_vector(&cast->dir, 1, 0);
		set_doub_vector(&cast->plane, 0, 0.66);
	}
}

t_cast	*init_cast(int x, int y, int dir)
{
	t_cast	*cast;

	cast = (t_cast *)malloc(sizeof(t_cast));
	if (!cast)
		print_error("Error");
	set_doub_vector(&cast->pos, (double)x + 0.5, (double)y + 0.5);
	init_dir_plane_vec(cast, dir);
	cast->time = get_time();
	cast->old_time = 0;
	return (cast);
}

t_data	*init_data(t_map_info *map_info)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		print_error("Error");
	data->map_info = map_info;
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	load_xpm_textures(map_info, &data->mlx);
	data->mlx.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp, \
	&data->mlx.line_length, &data->mlx.endian);
	data->cast = init_cast(map_info->user_x, map_info->user_y, \
	map_info->user_direction);
	data->draw = (t_draw *)malloc(sizeof(t_draw));
	if (!data->cast || !data->draw)
		print_error("Error");
	return (data);
}
