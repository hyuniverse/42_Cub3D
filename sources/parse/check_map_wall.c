/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:54:11 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/28 15:17:53 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

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
