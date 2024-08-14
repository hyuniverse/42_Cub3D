/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:27:35 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/08 16:18:42 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_2d_array(char **str)
{
	char **first_ptr;
	
	first_ptr = str;
	while(*str)
	{
		free(*str);
		*str = NULL;
		str++;
	}
	free(*str);
	free(first_ptr);
}

void	free_t_map_info(t_map_info *map_info)
{
	int	i;

	i = 0;
	free(map_info->file_path);
	free(map_info->north_texture);
	free(map_info->south_texture);
	free(map_info->west_texture);
	free(map_info->east_texture);
	while (i < map_info->map_height)
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map[i]);
	free(map_info->map);
	free(map_info);
}