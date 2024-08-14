/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:40:59 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/14 20:09:29 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "render.h"
# include "parse.h"
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map_info	*map_info;
	t_cast		*cast;
}	t_data;

/*-----free.c-----*/
void	free_2d_array(char **str);
void	free_t_map_info(t_map_info *map_info);
void	free_data(t_data *data);

/* debug.c @@@@제출 전 파일 및 하단 부 삭제!!!@@@@@ */
void	check(void);
void	check_parsing(t_map_info *map_info);

#endif