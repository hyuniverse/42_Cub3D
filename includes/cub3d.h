/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:40:59 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/18 15:09:23 by sehyupar         ###   ########.fr       */
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

/* debug.c @@@@제출 전 파일 및 하단 부 삭제!!!@@@@@ */
void	check(void);
void	check_parsing(t_map_info *map_info);

#endif