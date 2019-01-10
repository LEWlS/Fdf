# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:52:52 by lbonnete          #+#    #+#              #
#    Updated: 2019/01/10 16:03:08 by lbonnete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRC = main.c draw_line.c mapper.c tools.c dealers.c draw_square.c info_edit.c get_next_line/get_next_line.c

OBJ = 

LIB = libft/libft.a

INC = fdf.h

all: $(NAME) 

$(NAME): 
	gcc -I /usr/local/include  $(SRC) -L /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit libft/libft.a

p: all clean

clean:
	/bin/rm -f $(OBJ)
	echo "Objects Destroyed"

fclean:	clean
	/bin/rm -f $(NAME)
	echo "Project Destroyed"

re:	fclean all

norm:
	norminette $(SRC) $(INC)

.PHONY:	all clean fclean re norm

.SILENT: