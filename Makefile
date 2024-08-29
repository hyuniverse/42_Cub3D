# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 17:23:47 by siychoi           #+#    #+#              #
#    Updated: 2024/08/29 11:44:47 by sehyupar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3 #-g -fsanitize=address 
CLIB		= -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
RM			= rm
RMFLAG		= -f
INCLUDE		= ./includes/cub3d.h ./includes/parse.h ./includes/render.h
SRCS		= $(COMMON_SRCS) $(PARSE_SRCS) $(RENDER_SRCS)
OBJS		= $(SRCS:.c=.o)
COMMON_DIR	= ./sources/
PARSE_DIR	= ./sources/parse/
RENDER_DIR	= ./sources/render/
COMMON_SRCS	= $(addprefix $(COMMON_DIR), main.c utils.c free.c)
PARSE_SRCS	= $(addprefix $(PARSE_DIR), check_error.c check_map_wall.c check_map_wall2.c\
			  check_texture_path.c cub3d_split.c map_info.c map_info2.c struct_map.c \
			  texture_info_color.c texture_info.c utils.c)
RENDER_SRCS	= $(addprefix $(RENDER_DIR), render.c dda.c raycast_methods.c \
			  initialize.c utils.c hooks.c)

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -Imlx -c $< -o $@ -Iincludes

$(NAME) : $(OBJS)
		make -C Libft
		make -C mlx
		$(CC) $(CFLAGS) $(CLIB) -o $@ $^ -LLibft -lft -Iincludes

clean :
		$(RM) $(RMFLAG) $(OBJS)
		make -C mlx clean
		make -C Libft clean

fclean : clean
		$(RM) $(RMFLAG) $(NAME)
		$(RM) $(RMFLAG) ./Libft/libft.a

re : fclean
	$(MAKE) all

.PHONY : all clean fclean re