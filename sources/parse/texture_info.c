/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:53:04 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/28 16:08:40 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void	get_texture(t_map_info *map_info, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && map_info->texture_cnt < 6)
	{
		if (*line == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		else if (is_map_element(line) == TRUE)
			print_error("Error");
		else if (is_texture_element(line) != TRUE)
			print_error("Error");
		set_texture_info1(map_info, line);
		map_info->texture_cnt++;
		free(line);
		line = get_next_line(fd);
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

void	set_texture_info2(t_map_info *map_info, char **splited_line)
{
	if (cub3d_strcmp(splited_line[0], "EA") == 0 && \
	map_info->texture[EAST].path == NULL)
		map_info->texture[EAST].path = \
		ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]) - 1);
	else if (cub3d_strcmp(splited_line[0], "F") == 0 && \
	map_info->floor_color == (unsigned int)-1)
		map_info->floor_color = str_to_rgb(splited_line[1]);
	else if (cub3d_strcmp(splited_line[0], "C") == 0 && \
	map_info->ceiling_color == (unsigned int)-1)
		map_info->ceiling_color = str_to_rgb(splited_line[1]);
	else
		print_error("Error0");
}

void	set_texture_info1(t_map_info *map_info, char *line)
{
	char	**splited_line;

	splited_line = cub3d_split(line, ' ');
	if (cub3d_strcmp(splited_line[0], "NO") == 0 && \
	map_info->texture[NORTH].path == NULL)
		map_info->texture[NORTH].path = \
		ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]) - 1);
	else if (cub3d_strcmp(splited_line[0], "SO") == 0 && \
	map_info->texture[SOUTH].path == NULL)
		map_info->texture[SOUTH].path = \
		ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]) - 1);
	else if (cub3d_strcmp(splited_line[0], "WE") == 0 && \
	map_info->texture[WEST].path == NULL)
		map_info->texture[WEST].path = \
		ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]) - 1);
	else
		set_texture_info2(map_info, splited_line);
	free_2d_array(splited_line);
}
