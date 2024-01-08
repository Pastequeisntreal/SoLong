# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:57:34 by gberthol          #+#    #+#              #
#    Updated: 2023/11/27 10:36:58 by gberthol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    so_long

CFLAGS    =	-Wall -Wextra -Werror -Ilibft -Iincludes -I /usr/local/include

SRC	=	src/main.c					\
		src/pathfinder_map.c		\
		src/ft_map.c				\
		src/display_map.c			\
		src/main_loop.c				\
		src/move_chara.c			\
		src/struct_constructor.c	\
		src/win_handling.c			\
		src/is_map_solutionable.c	\
		src/map_handling.c

OBJ	=	$(SRC:.c=.o)

LIB	=	libft.a

HEAD	=	libft.h	\
			so_long.h

%.o:%.c	$(HEAD) $(LIB)
	cc $(CFLAGS) -c $< -o $@  -I/usr/include -Imlx_linux

all:        $(LIB) $(NAME)

$(LIB):
	make -C libft/

$(NAME):	$(OBJ) Makefile
	cc -o $(NAME) $(OBJ) $(CFLAGS) -Llibft -lft -Lmlx_linux -lmlx_Linux -L. -Imlx_linux -lXext -lX11 -lm -lz -g3

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean:	clean
	$(RM) $(NAME) libft/libft.a

re:		fclean
	$(MAKE)

.PHONY: all clean fclean re
