# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:57:34 by gberthol          #+#    #+#              #
#    Updated: 2023/12/04 15:46:50 by gberthol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    libft.a

CFLAGS    =	-Wall -Wextra -Werror
 
SRC	=	ft_atoi.c				\
		ft_calloc.c				\
		ft_itoa.c				\
		ft_memcpy.c				\
		ft_memset.c				\
		ft_putendl_fd.c			\
		ft_putstr_fd.c			\
		ft_strchr.c				\
		ft_striteri.c			\
		ft_strlcat.c			\
		ft_strlen.c				\
		ft_strncmp.c			\
		ft_strtrim.c			\
		ft_tocase.c				\
		ft_bzero.c				\
		ft_isft.c				\
		ft_memchr.c				\
		ft_memmove.c			\
		ft_putchar_fd.c			\
		ft_putnbr_fd.c			\
	    ft_split.c				\
		ft_strdup.c				\
		ft_strjoin.c			\
	    ft_strlcpy.c			\
		ft_strmapi.c			\
		ft_strnstr.c			\
		ft_substr.c				\
		ft_lstnew.c				\
		ft_lstadd_front.c		\
		ft_lstsize.c			\
		ft_lstlast.c			\
		ft_lstdelone.c			\
		ft_lstadd_back.c		\
		ft_lstclear.c			\
		ft_lstiter.c			\
		ft_printf.c				\
		ft_putunbr_fd.c			\
		ft_puthexa.c			\
		get_next_line.c			\
		get_all_file.c			\
		get_next_line_utils.c	\
		ft_linelen.c			\
		ft_lstmap.c

OBJ	=	$(SRC:.c=.o)

HEAD	=	libft.h			\
		get_next_line.h

%.o:%.c	$(HEAD)
	cc $(CFLAGS) -c $< -o $@

all:        $(NAME)

$(NAME):	$(OBJ) Makefile
	ar -rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) libft.a

re:		fclean
	$(MAKE)

.PHONY: all clean fclean re
