/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:40:59 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/15 20:56:49 by sehyupar         ###   ########.fr       */
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


/* debug.c @@@@제출 전 파일 및 하단 부 삭제!!!@@@@@ */
void	check(void);
void	check_parsing(t_map_info *map_info);


#endif