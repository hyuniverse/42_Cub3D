/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:56:35 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/14 18:42:49 by sehyupar         ###   ########.fr       */
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
	//check_parsing(map_info);
	data = init_data(map_info);
	render(data);
	free_data(data); // 내부에서 map_info free
	return (0);
}
