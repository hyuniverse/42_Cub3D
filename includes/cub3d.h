/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:40:59 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/28 15:06:32 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include "struct.h"
# include "parse.h"
# include "render.h"

# define TRUE 1
# define FALSE 0

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

/*-----utils.c-----*/
void	print_error(char *error_msg);

/*-----free.c-----*/
void	free_2d_array(char **str);
void	free_t_map_info(t_map_info *map_info);
void	free_data(t_data *data);

#endif