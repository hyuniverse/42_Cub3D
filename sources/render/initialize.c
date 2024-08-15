/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:40:49 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/15 20:49:25 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render.h"

unsigned int	*get_img_data(t_data *data, t_texture *tex, int idx)
{
	int	i;
	int	j;
	unsigned int	*result;
	unsigned int	*tmp;

	//printf("path = %s\n", tex[idx].path);
	data->img = mlx_xpm_file_to_image(data->mlx, tex[idx].path, \
	&tex[idx].width, &tex[idx].height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 100, 100);
	printf("%d : w=%d, h=%d\n", idx, tex[idx].width, tex[idx].height);
	getchar();
	if (!data->img)
		return (0);
	tmp = (unsigned int *)mlx_get_data_addr(data->img, &data->bpp, &data->line_length, \
	&data->endian);
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
			result[tex->width * i + j] = tmp[tex->width * i + j];
	}
	mlx_destroy_image(data->mlx, data->img);
	return (result);
}

void	load_xpm_textures(t_map_info *map_info, t_data *data)
{
	t_texture	*texture;
	int			i;

	texture = map_info->texture;
	i = -1;
	while (++i < 4)
	{
		texture->data = get_img_data(data, texture, i);
		if (!texture->data)
			printf("!!!\n");
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
	cast->time = 0;
	cast->old_time = 0;
	return (cast);
}

t_data	*init_data(t_map_info *map_info)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->map_info = map_info;
	//mlx
	data->mlx = mlx_init();
	//win
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	//img
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	//addr, bits_per_pixel, line_length, endian
	// tex array
	printf("load_xpm\n");
	load_xpm_textures(map_info, data);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, \
	&data->line_length, &data->endian);
	//cast
	printf("init_cast\n");
	data->cast = init_cast(map_info->user_x, map_info->user_y, \
	map_info->user_direction);
	if (!data->cast)
		return (0);
	return (data);
}
