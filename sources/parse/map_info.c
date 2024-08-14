/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:48:08 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/14 16:50:33 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void	set_user_info(t_map_info *map_info, int x, int y);

void	get_map(t_map_info *map_info, int fd)
{
	set_map_size(map_info, fd);
	close(fd);
	make_map(map_info);
	check_one_person_in_map(map_info);
	check_wall(map_info);
}

void	check_one_person_in_map(t_map_info *map_info)
{
	int	person_flag;
	int	i;
	int	j;

	person_flag = FALSE;
	i = 0;
	while (i < map_info->map_height)
	{
		j = 0;
		while (j < map_info->map_width)
		{
			if (map_info->map[i][j] == 'N' || map_info->map[i][j] == 'W' || \
			map_info->map[i][j] == 'E' || map_info->map[i][j] == 'S')
			{
				set_user_info(map_info, j, i);
				if (person_flag == TRUE)
					print_error("Error");
				person_flag = TRUE;
			}
			j++;
		}
		i++;
	}
	map_info->map[map_info->user_y][map_info->user_x] = '0';
}

static void	set_user_info(t_map_info *map_info, int x, int y)
{
	map_info->user_x = x;
	map_info->user_y = y;
	if (map_info->map[y][x] == 'N')
		map_info->user_direction = NORTH;
	else if (map_info->map[y][x] == 'S')
		map_info->user_direction = SOUTH;
	else if (map_info->map[y][x] == 'E')
		map_info->user_direction = EAST;
	else if (map_info->map[y][x] == 'W')
		map_info->user_direction = WEST;
}

void	make_map(t_map_info *map_info)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_info->file_path, O_RDONLY);
	line = skip_to_map(fd);
	init_map_array(map_info);
	while (line != NULL)
	{
		copy_map_line(map_info, line, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}

void	copy_map_line(t_map_info *map_info, char *line, int idx)
{
	int	line_len;
	int	i;

	i = 0;
	line_len = ft_strlen(line);
	while (i < map_info->map_width)
	{
		if (i < line_len)
		{
			if (line[i] == '\n')
				map_info->map[idx][i] = ' ';
			else
				map_info->map[idx][i] = line[i];
		}
		else
			map_info->map[idx][i] = 32;
		i++;
	}
	map_info->map[idx][i] = '\0';
}

void	init_map_array(t_map_info *map_info)
{
	int	i;

	i = 0;
	map_info->map = (char **)malloc(sizeof(char *) * (map_info->map_height + 1));
	if (map_info->map == NULL)
		print_error("Error");
	while (i < map_info->map_height)
	{
		(map_info->map)[i] = (char *)malloc(sizeof(char) * (map_info->map_width + 1));
		if ((map_info->map)[i] == NULL)
			print_error("Error");
		i++;
	}
	(map_info->map)[i] = NULL;
}

char	*skip_to_map(int fd)
{
	char *gnl_return;

	while ((gnl_return = get_next_line(fd)) != NULL)
	{
		if (is_map_element(gnl_return) == TRUE)
			break;
		free(gnl_return);
	}
	return (gnl_return);
}

int	is_valid_map_element(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S' &&\
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
