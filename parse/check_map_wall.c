/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:54:11 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/08 15:46:28 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_north_wall(t_map_info *map_info, int x, int y)
{
	if (y - 1 < 0)
		print_error("Error");
	else if (map_info->map[y - 1][x] == ' ')
		print_error("Error");
}

void	check_south_wall(t_map_info *map_info, int x, int y)
{
	if (y + 1 > map_info->map_height)
		print_error("Error");
	else if (map_info->map[y + 1][x] == ' ')
		print_error("Error");
}

void	check_east_wall(t_map_info *map_info, int x, int y)
{
	if (x + 1 > map_info->map_width)
		print_error("Error");
	else if (map_info->map[y][x + 1] == ' ')
		print_error("Error");
}

void	check_west_wall(t_map_info *map_info, int x, int y)
{
	if (x - 1 < 0)
		print_error("Error");
	else if (map_info->map[y][x - 1] == ' ')
		print_error("Error");
}

void	check_nsew_wall(t_map_info *map_info, int x, int y)
{
	check_north_wall(map_info, x, y);
	check_south_wall(map_info, x, y);
	check_east_wall(map_info, x, y);
	check_west_wall(map_info, x, y);
}

void	check_wall(t_map_info *map_info)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < map_info->map_height)
	{
		x = 0;
		while (x < map_info->map_width)
		{
			if (map_info->map[y][x] == 'N' || map_info->map[y][x] == 'S' ||\
			  map_info->map[y][x] == 'W' ||  map_info->map[y][x] == 'E' ||\
			  map_info->map[y][x] == '0' )
				check_nsew_wall(map_info, x, y);
			x++;
		}
		y++;
	}
}