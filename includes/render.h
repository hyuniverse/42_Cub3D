/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:41:04 by sehyupar          #+#    #+#             */
/*   Updated: 2024/08/14 20:41:25 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define WIDTH 640
# define HEIGHT 480

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define CLOSE_BTN 17

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

typedef struct s_cast
{
	t_doub_vector	pos;
	t_doub_vector	dir;
	t_doub_vector	plane;
	t_doub_vector	camera;//y도 필요한가?
	t_doub_vector	ray_dir;
	t_doub_vector	side_dist;
	t_doub_vector	delta_dist;
	t_int_vector	step;
	t_int_vector	map;
	double			perp_wall_dist;
	double			time;
	double			old_time;
	int				hit;
	int				side;
}	t_cast;

// hooks.c
int		key_hook(int keycode);
int		exit_hook(void);

// initialize.c
t_data	*init_data(t_data *data);

//utils.c
void	set_doub_vector(t_doub_vector *vec, double x, double y);
void	set_int_vector(t_int_vector *vec, int x, int y);

#endif