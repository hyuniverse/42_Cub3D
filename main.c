/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:56:35 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/14 14:49:04 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse/parse.h"

void	check(void)
{
	system("leaks parsing");
}

void	check_parsing(t_map_info *map_info)
{
	printf("map_info->north_texture = %s\n", map_info->north_texture);
	printf("map_info->south_texture = %s\n", map_info->south_texture);
	printf("map_info->east_texture = %s\n", map_info->west_texture);
	printf("map_info->west_texture = %s\n", map_info->east_texture);
	printf("map_info->floor_color = %d\n", map_info->floor_color);
	printf("map_info->ceiling_color = %d\n", map_info->ceiling_color);
	printf("map_info->map_user_x = %d\n", map_info->user_x);
	printf("map_info->map_user_y = %d\n", map_info->user_y);
	printf("map_info->map_user_direction = %d\n", map_info->user_direction);
	printf("map_info->map_width = %d\n", map_info->map_width);
	printf("map_info->map_height = %d\n", map_info->map_height);
	int	i;

	i = 0;
	while (i < map_info->map_height)
	{
		printf("map_info->map[i] = %s\n", map_info->map[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_map_info	*map_info;

	//atexit(check);
	check_argv(argc, argv);
	map_info = init_map_info(argv[1]);
	set_map_info(map_info);
	check_parsing(map_info);
	free_t_map_info(map_info);
}

