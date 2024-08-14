/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:09:54 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/08 16:46:53 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../libft/libft.h"
# include "../libft/get_next_line_bonus.h"

# include <fcntl.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct s_map_info
{
	char			*file_path;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
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

/*-----check_error.c-----*/
void	check_argv(int argc, char *argv[]);

/*-----check_map_wall.c-----*/
void	check_wall(t_map_info *map_info);

/*-----check_texture_path.c-----*/
void	check_texture_path(t_map_info *map_info, char *id);

/*-----cub3d_split.c-----*/
char	**cub3d_split(char const *s, char c);

/*-----free.c-----*/
void	free_2d_array(char **str);
void	free_t_map_info(t_map_info *map_info);
void	get_map(t_map_info *map_info, int fd);

/*-----map_info.c-----*/
void	get_map(t_map_info *map_info, int fd);
void	check_one_person_in_map(t_map_info *map_info);
void	make_map(t_map_info *map_info);
void	copy_map_line(t_map_info *map_info, char *line, int idx);
void	init_map_array(t_map_info *map_info);
char	*skip_to_map(int fd);

int	cub3d_strlen(char *str);
int	is_valid_map_element(char *line);
void	set_map_width(t_map_info *map_info, char *line);
void	set_map_size(t_map_info *map_info, int fd);

/*-----struct_map.c-----*/
t_map_info	*init_map_info(char *file_name);
void	set_map_info(t_map_info *map_info);
int		is_map_element(char *line);

/*-----texture_info.c-----*/
void	get_texture(t_map_info *map_info, int fd);
int		is_texture_element(char *line);
int		is_texture_identifier(char *identifier);
void	set_texture_info(t_map_info *map_info, char *line);

/*-----texture_info_color.c-----*/
void	is_valid_color_line(char *line, int i, int comma_cnt, int num_cnt);
unsigned int	str_to_rgb(char *str);
void	str_to_color(char *str, int num_idx, int i, int rgb_cnt, unsigned int *rgb);

/*-----utils.c-----*/
int		open_file(char *path);
int		cub3d_strcmp(const char *s1, const char *s2);
void	print_error(char *error_msg);
int		is_num(char c);

#endif