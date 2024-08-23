/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:56:35 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/23 12:55:20 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_map_info	*map_info;
	t_data		*data;

	//atexit(check);
	check_argv(argc, argv);
	map_info = init_map_info(argv[1]);
	set_map_info(map_info);
	check_parsing(map_info);
	data = init_data(map_info);
	render(data, &data->mlx);
	free_data(data);
	return (0);
}
