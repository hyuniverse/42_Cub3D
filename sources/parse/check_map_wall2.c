/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:15:54 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/28 15:16:52 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

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
			if (map_info->map[y][x] == 'N' || map_info->map[y][x] == 'S' || \
			map_info->map[y][x] == 'W' || map_info->map[y][x] == 'E' || \
			map_info->map[y][x] == '0' )
				check_nsew_wall(map_info, x, y);
			x++;
		}
		y++;
	}
}
