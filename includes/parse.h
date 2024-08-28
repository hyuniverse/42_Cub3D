/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:09:54 by siychoi           #+#    #+#             */
/*   Updated: 2024/08/28 16:22:46 by siychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/get_next_line_bonus.h"
# include "cub3d.h"

/*-----check_error.c-----*/
void			check_argv(int argc, char *argv[]);

/*-----check_map_wall.c-----*/
void			check_wall(t_map_info *map_info);
void			check_nsew_wall(t_map_info *map_info, int x, int y);

/*-----check_texture_path.c-----*/
void			check_texture_path(t_map_info *map_info, char *id);

/*-----cub3d_split.c-----*/
char			**cub3d_split(char const *s, char c);

/*-----map_info.c-----*/
void			get_map(t_map_info *map_info, int fd);
void			check_one_person_in_map(t_map_info *map_info);
void			make_map(t_map_info *map_info);
void			copy_map_line(t_map_info *map_info, char *line, int idx);
void			init_map_array(t_map_info *map_info);
char			*skip_to_map(int fd);
int				cub3d_strlen(char *str);
int				is_valid_map_element(char *line);
void			set_map_width(t_map_info *map_info, char *line);
void			set_map_size(t_map_info *map_info, int fd);

/*-----struct_map.c-----*/
t_map_info		*init_map_info(char *file_name);
void			set_map_info(t_map_info *map_info);
int				is_map_element(char *line);

/*-----texture_info.c-----*/
void			get_texture(t_map_info *map_info, int fd);
int				is_texture_element(char *line);
int				is_texture_identifier(char *identifier);
void			set_texture_info1(t_map_info *map_info, char *line);

/*-----texture_info_color.c-----*/
void			is_valid_color_line(char *line, int i, int comma_cnt, \
int num_cnt);
unsigned int	str_to_rgb(char *str);
void			str_to_color(char *str, int num_idx, int i, unsigned int *rgb);

/*-----utils.c-----*/
int				open_file(char *path);
int				cub3d_strcmp(const char *s1, const char *s2);
void			print_error(char *error_msg);
int				is_num(char c);

#endif