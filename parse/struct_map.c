/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:59:14 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/08 16:47:19 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_map_info	*init_map_info(char *file_path)
{
	t_map_info	*map_info;

	map_info = (t_map_info*)malloc(sizeof(t_map_info));
	if (map_info == NULL)
		exit(1);
	map_info->file_path = ft_strdup(file_path);
	map_info->north_texture = NULL;
	map_info->south_texture = NULL;
	map_info->west_texture = NULL;
	map_info->east_texture = NULL;
	map_info->floor_color = (unsigned int)-1;
	map_info->ceiling_color = (unsigned int)-1;
	map_info->texture_cnt = 0;
	map_info->user_x = -1;
	map_info->user_y = -1;
	map_info->user_direction = -1;
	map_info->map = NULL;
	map_info->map_height = 0;
	map_info->map_width = 0;
	return (map_info);
}

void	set_map_info(t_map_info *map_info)
{
	int	fd;
	
	fd = open_file(map_info->file_path);
	get_texture(map_info, fd);
	get_map(map_info, fd);
}

int	is_map_element(char *line)
{
	if (line[0] == '1')
		return (TRUE);
	else if (line[0] == '0')
		return (TRUE);
	else if (line[0] == ' ')
		return (TRUE);
	return (FALSE);
}
