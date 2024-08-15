/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:40:15 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/15 19:19:08 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void	check_north_path(t_map_info *map_info);
static void	check_south_path(t_map_info *map_info);
static void	check_east_path(t_map_info *map_info);
static void	check_west_path(t_map_info *map_info);

void	check_texture_path(t_map_info *map_info, char *id)
{
	if (*id == 'F' || *id == 'C')
		return ;
	if (cub3d_strcmp(id, "NO") == 0)
		check_north_path(map_info);
	else if (cub3d_strcmp(id, "SO") == 0)
		check_south_path(map_info);
	else if (cub3d_strcmp(id, "WE") == 0)
		check_west_path(map_info);
	else if (cub3d_strcmp(id, "EA") == 0)
		check_east_path(map_info);
}

static void	check_north_path(t_map_info *map_info)
{
	char	*path;
	int		fd;

	path = map_info->texture[NORTH].path;
	if (cub3d_strcmp(path, map_info->texture[SOUTH].path) == 0)
		print_error("Error");
	else if (cub3d_strcmp(path, map_info->texture[WEST].path) == 0)
		print_error("Error");
	else if (cub3d_strcmp(path, map_info->texture[EAST].path) == 0)
		print_error("Error");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Error");
	close(fd);
}

static void	check_south_path(t_map_info *map_info)
{
	char	*path;
	int		fd;

	path = map_info->texture[SOUTH].path;
	if (cub3d_strcmp(path, map_info->texture[NORTH].path) == 0)
		print_error("Error");
	else if (cub3d_strcmp(path, map_info->texture[WEST].path) == 0)
		print_error("Error");
	else if (cub3d_strcmp(path, map_info->texture[EAST].path) == 0)
		print_error("Error");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Error");
	close(fd);
}

static void	check_west_path(t_map_info *map_info)
{
	char	*path;
	int		fd;

	path = map_info->texture[WEST].path;
	if (cub3d_strcmp(path, map_info->texture[SOUTH].path) == 0)
		print_error("Error");
	else if (cub3d_strcmp(path, map_info->texture[NORTH].path) == 0)
		print_error("Error");
	else if (cub3d_strcmp(path, map_info->texture[EAST].path) == 0)
		print_error("Error");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Error");
	close(fd);
}

static void	check_east_path(t_map_info *map_info)
{
	char	*path;
	int		fd;

	path = map_info->texture[EAST].path;
	if (cub3d_strcmp(path, map_info->texture[SOUTH].path) == 0)
		print_error("Error");
	else if (cub3d_strcmp(path, map_info->texture[WEST].path) == 0)
		print_error("Error");
	else if (cub3d_strcmp(path, map_info->texture[NORTH].path) == 0)
		print_error("Error");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Error");
	close(fd);
}
