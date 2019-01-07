# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:52:52 by lbonnete          #+#    #+#              #
#    Updated: 2019/01/07 16:57:30 by lbonnete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf

FLAGS = -Wall -Wextra -Werror

SRC = 

OBJ = 

LIB = libft/libft.a

INC = fdf.h

all: $(NAME)

$(NAME):
	@echo "\nBuilding Project...\n"
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@gcc -o $(NAME) $(OBJ)
	@echo "Compilation Successful"
	@echo "Project Ready"

p: all clean

clean:
	@/bin/rm -f $(OBJ)
	@echo "Objects Destroyed"

fclean:	clean
		@/bin/rm -f $(NAME)
		@echo "Project Destroyed"

re:	fclean all

norm:
	@norminette $(SRC) $(INC)

.PHONY:	all clean fclean re norm