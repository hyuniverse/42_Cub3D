/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:56:35 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/28 16:41:52 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_map_info	*map_info;
	t_data		*data;

	check_argv(argc, argv);
	map_info = init_map_info(argv[1]);
	set_map_info(map_info);
	data = init_data(map_info);
	render(data, &data->mlx);
	free_data(data);
	return (0);
}
