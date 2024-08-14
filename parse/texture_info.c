/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:53:04 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/08 16:36:24 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_texture(t_map_info *map_info, int fd)
{
	char	*gnl_return;

	while (map_info->texture_cnt < 6 && (gnl_return = get_next_line(fd)) != NULL)
	{
		if (*gnl_return == '\n')
		{
			free(gnl_return);
			continue ;
		}
		else if (is_map_element(gnl_return) == TRUE)
			print_error("Error");
		else if (is_texture_element(gnl_return) != TRUE)
			print_error("Error");
		set_texture_info(map_info, gnl_return);
		map_info->texture_cnt++;
		free(gnl_return);
	}
	if (map_info->texture_cnt < 6)
		print_error("empty file?\n");
}

int	is_texture_element(char *line)
{
	char	**splited_line;
	int		result;
	
	splited_line = cub3d_split(line, ' ');
	result = TRUE;
	if (is_texture_identifier(splited_line[0]) == FALSE)
		result = FALSE;
	else if (splited_line[1] == NULL)
		result = FALSE;
	else if (splited_line[2] != NULL)
		result = FALSE;
	free_2d_array(splited_line);
	return (result);	
}

int	is_texture_identifier(char *identifier)
{
	if (cub3d_strcmp(identifier, "NO") == 0)
		return (TRUE);
	else if (cub3d_strcmp(identifier, "SO") == 0)
		return (TRUE);
	else if (cub3d_strcmp(identifier, "WE") == 0)
		return (TRUE);
	else if (cub3d_strcmp(identifier, "EA") == 0)
		return (TRUE);
	else if (cub3d_strcmp(identifier, "F") == 0)
		return (TRUE);
	else if (cub3d_strcmp(identifier, "C") == 0)
		return (TRUE);
	return (FALSE);
}

void	set_texture_info(t_map_info *map_info, char *line)
{
	char	**splited_line;

	splited_line = cub3d_split(line, ' ');
	if (cub3d_strcmp(splited_line[0], "NO") == 0 && map_info->north_texture == NULL)
		map_info->north_texture = ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]) - 1);
	else if (cub3d_strcmp(splited_line[0], "SO") == 0 && map_info->south_texture == NULL)
		map_info->south_texture = ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]) - 1);
	else if (cub3d_strcmp(splited_line[0], "WE") == 0 && map_info->west_texture == NULL)
		map_info->west_texture = ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]) - 1);
	else if (cub3d_strcmp(splited_line[0], "EA") == 0 && map_info->east_texture == NULL)
		map_info->east_texture = ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]) - 1);
	else if (cub3d_strcmp(splited_line[0], "F") == 0 && map_info->floor_color == (unsigned int)-1)
		map_info->floor_color = str_to_rgb(splited_line[1]);
	else if (cub3d_strcmp(splited_line[0], "C") == 0 && map_info->ceiling_color == (unsigned int)-1)
		map_info->ceiling_color = str_to_rgb(splited_line[1]);
	else
		print_error("Error0");
	//check_texture_path(map_info, splited_line[0]);
	free_2d_array(splited_line);
}
