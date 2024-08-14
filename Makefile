# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siychoi <siychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 17:23:47 by siychoi           #+#    #+#              #
#    Updated: 2024/08/08 16:54:42 by siychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= parsing
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
#-fsanitize=address
RM			= rm
RMFLAG		= -f
SRC			= main ./parse/check_error ./parse/check_map_wall ./parse/check_texture_path ./parse/cub3d_split ./parse/free ./parse/map_info ./parse/struct_map ./parse/texture_info ./parse/texture_info_color ./parse/utils
SRCS		= $(addsuffix .c, $(SRC))
OBJS		= $(SRCS:.c=.o)

all : $(NAME)

clean :
		$(RM) $(RMFLAG) $(OBJS)
		make -C Libft clean

fclean :
		$(RM) $(RMFLAG) $(OBJS) $(NAME)
		make -C Libft fclean

re : fclean
	$(MAKE) all

bonus : 

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME) : $(OBJS)
		make -C Libft
		$(CC) $(CFLAGS) -o $@ $^ -LLibft -lft

.PHONY : all clean fclean re