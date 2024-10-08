/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:11:28 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/28 15:08:31 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_texture
{
	char			*path;
	unsigned int	*data;
	int				width;
	int				height;
}	t_texture;

typedef struct s_map_info
{
	char			*file_path;
	t_texture		texture[4];
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	int				texture_cnt;
	int				user_x;
	int				user_y;
	int				user_direction;
	char			**map;
	int				map_height;
	int				map_width;
}t_map_info;

typedef struct s_cub
{
	t_map_info		map_info;
}t_cub;

typedef struct s_doub_vector
{
	double	x;
	double	y;
}	t_doub_vector;

typedef struct s_int_vector
{
	int	x;
	int	y;
}	t_int_vector;

typedef struct s_draw
{
	double			perp_wall_dist;
	int				side;
	int				line_height;
	int				start;
	int				end;
	double			step;
	double			wall_x;
	int				tex_num;
	double			tex_pos;
	t_int_vector	tex;
}	t_draw;

typedef struct s_cast
{
	t_doub_vector	pos;
	t_doub_vector	dir;
	t_doub_vector	plane;
	t_doub_vector	camera;
	t_doub_vector	ray_dir;
	t_doub_vector	side_dist;
	t_doub_vector	delta_dist;
	t_int_vector	step;
	t_int_vector	map;
	double			time;
	double			old_time;
	double			move_speed;
	double			rot_speed;
	int				hit;
}	t_cast;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}	t_mlx;

typedef struct s_data
{
	t_mlx		mlx;
	t_map_info	*map_info;
	t_cast		*cast;
	t_draw		*draw;
}	t_data;

#endif