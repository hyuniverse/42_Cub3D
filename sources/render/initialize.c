/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:40:49 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/16 18:53:17 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

unsigned int	*get_img_data(t_mlx *mlx, t_texture *tex, int idx)
{
	int	i;
	int	j;
	unsigned int	*result;
	unsigned int	*tmp;

	//printf("path = %s\n", tex[idx].path);
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, tex[idx].path, \
	&tex[idx].width, &tex[idx].height);
	if (!mlx->img)
		return (0);
	tmp = (unsigned int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	result = (unsigned int *)malloc(sizeof(unsigned int) * tex[idx].width * tex[idx].height);
	if (!result)
	{
		printf("allocation error\n");
		return (0);
	}
	i = -1;
	while (++i < tex[idx].height)
	{
		j = -1;
		while (++j < tex[idx].width)
		{
			result[tex[idx].width * i + j] = tmp[tex[idx].width * i + j];
			//printf("%d", result[tex[idx].width * i + j]);
		}
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
			printf("!!!\n");//error_exit
		//path free를 여기서 할까..? 
	}
}

t_cast	*init_cast(int x, int y, int dir)
{
	t_cast	*cast;

	cast = (t_cast *)malloc(sizeof(t_cast));
	if (!cast)
		return (0);
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
	set_int_vector(&cast->map, 0, 0);
	cast->time = 0;
	cast->old_time = 0;
	return (cast);
}

t_draw	*init_draw(void)
{
	t_draw	*draw;

	draw = (t_draw *)malloc(sizeof(t_draw));
	if (!draw)
		return (0);
	return (draw);
}

t_data	*init_data(t_map_info *map_info)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->map_info = map_info;
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	load_xpm_textures(map_info, &data->mlx);
	data->mlx.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp, \
	&data->mlx.line_length, &data->mlx.endian);
	data->cast = init_cast(map_info->user_x, map_info->user_y, \
	map_info->user_direction);
	data->draw = init_draw();
	if (!data->cast || !data->draw)
		return (0);
	return (data);
}
