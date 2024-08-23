/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:41:04 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/23 13:01:04 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <math.h>
# include "cub3d.h"

# define WIDTH 640
# define HEIGHT 480

# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define CLOSE_BTN 17
# define KEY_PRESS 2
# define KEY_RELEASE 3

/* render.c */
void			draw(t_data *data, t_mlx *mlx);
void			render(t_data *data, t_mlx *mlx);

/* hooks.c */
int				key_press_hook(int keycode, t_data *data);
int				exit_hook(void);
int				key_release_hook(int keycode, t_data *data);

/* initialize.c */
t_data			*init_data(t_map_info *map_info);

/* utils.c */
void			set_doub_vector(t_doub_vector *vec, double x, double y);
void			set_int_vector(t_int_vector *vec, int x, int y);
double			get_time(void);
double			get_delta(double ray_dir);
int				get_dir(double component_value, char component, int sign);

/* raycast_methods.c */
void			set_wall_dir(t_cast *cast, t_draw *draw);
void			calc_draw_vars(t_draw *draw);
void			calc_tex_info(t_draw *draw, t_texture *texture, t_cast *cast);
unsigned int	get_color(t_draw *draw, t_texture *texture);
void			modify_speed(t_cast *cast);

/* dda.c */
void			dda(t_cast *cast, t_map_info *map, \
t_draw *draw, int x);

#endif