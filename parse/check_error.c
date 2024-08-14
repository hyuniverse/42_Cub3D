/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:59:59 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/01 20:04:41 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_map_path(char *map_path);

void	check_argv(int argc, char *argv[])
{
	if (argc != 2)
		print_error("Invalid number of arguments");
	check_map_path(argv[1]);
}

static void	check_map_path(char *map_path)
{
	int	len;

	len = ft_strlen(map_path);
	if (len < 4)
		print_error("check .cub file");
	if (map_path[len - 1] != 'b' || \
		map_path[len - 2] != 'u' || \
		map_path[len - 3] != 'c' || \
		map_path[len - 4] != '.')
		print_error("check .cub file");
}
