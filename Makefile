# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trabut <trabut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:52:52 by lbonnete          #+#    #+#              #
#    Updated: 2019/02/25 12:40:13 by trabut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRC = main.c draw_line.c draw_line_hud.c mapper.c tools.c dealers.c info_edit.c get_next_line.c draw_map.c hud.c proj_caval.c cross_drawer.c cross_drawer_caval.c

LIB = libft/libft.a

OBJ := $(patsubst %.c,%.o,$(SRC))

INC = fdf.h

all: $(NAME) 

$(NAME): $(OBJ)
	make  -C libft  
	gcc $(FLAGS) -c $(SRC) -I $(INC)
	gcc -o $(NAME) -I /usr/local/include  $(OBJ) -L /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit libft/libft.a
	echo "fdf ready"
lib: make  -C libft  

p: all clean

clean:
	make clean -C libft 
	/bin/rm -f $(OBJ)
	echo "Objects Destroyed"

fclean:	clean
	make fclean -C libft 
	/bin/rm -f $(NAME)
	echo "Project Destroyed"

re:	fclean all

norm:
	norminette $(SRC) $(INC)

.PHONY:	all clean fclean re norm p

.SILENT: