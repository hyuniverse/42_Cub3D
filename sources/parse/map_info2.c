/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:12:13 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/28 16:41:07 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void	init_map_array(t_map_info *map_info)
{
	int	i;

	i = 0;
	map_info->map = malloc(sizeof(char *) * (map_info->map_height + 1));
	if (map_info->map == NULL)
		print_error("Error");
	while (i < map_info->map_height)
	{
		(map_info->map)[i] = malloc(sizeof(char) * (map_info->map_width + 1));
		if ((map_info->map)[i] == NULL)
			print_error("Error");
		i++;
	}
	(map_info->map)[i] = NULL;
}

char	*skip_to_map(int fd)
{
	char	*gnl_return;

	gnl_return = get_next_line(fd);
	while (gnl_return != NULL)
	{
		if (is_map_element(gnl_return) == TRUE)
			break ;
		free(gnl_return);
		gnl_return = get_next_line(fd);
	}
	return (gnl_return);
}

int	is_valid_map_element(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && \
		line[i] != 'N' && line[i] != 'S' && \
		line[i] != 'W' && line[i] != 'E' && line[i] != ' ' && line[i] != '\n')
			print_error("Error");
		i++;
	}
	return (TRUE);
}

void	set_map_width(t_map_info *map_info, char *line)
{
	int	len;

	len = cub3d_strlen(line);
	if (map_info->map_width < len)
		map_info->map_width = len;
}

void	set_map_size(t_map_info *map_info, int fd)
{
	char	*gnl_return;

	while (TRUE)
	{
		gnl_return = get_next_line(fd);
		if (gnl_return == NULL || gnl_return[0] != '\n')
			break ;
		free(gnl_return);
	}
	while (TRUE)
	{
		if (gnl_return == NULL)
			break ;
		else if (gnl_return[0] == '\n')
			print_error("Error");
		else if (is_valid_map_element(gnl_return) == TRUE)
		{
			map_info->map_height += 1;
			set_map_width(map_info, gnl_return);
		}
		else
			print_error("Error");
		free(gnl_return);
		gnl_return = get_next_line(fd);
	}
}
