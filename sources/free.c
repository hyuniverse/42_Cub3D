/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:27:35 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/15 21:01:26 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void	free_2d_array(char **str)
{
	char	**first_ptr;

	first_ptr = str;
	while (*str)
	{
		free(*str);
		*str = NULL;
		str++;
	}
	free(*str);
	free(first_ptr);
}

void	free_texture(t_texture *tex)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (tex[i].data)
			printf("%dth data exist\n", i);
		else
			printf("%dth data doesn't exist\n", i);
	}
	i = -1;
	while (++i < 4)
	{
		free(tex[i].data);
		printf("freed data\n");
		free(tex[i].path);
		printf("freed path\n");
	}
}

void	free_t_map_info(t_map_info *map_info)
{
	int	i;

	i = 0;
	free(map_info->file_path);
	free_texture(map_info->texture);
	while (i < map_info->map_height)
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map[i]);
	free(map_info->map);
	free(map_info);
}

void	free_data(t_data *data)
{
	free_t_map_info(data->map_info);
	printf("freed map\n");
	free(data->cast);
	printf("freed cast\n");
	free(data);
}
