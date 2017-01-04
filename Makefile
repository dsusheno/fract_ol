# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/10 15:41:47 by dsusheno          #+#    #+#              #
#    Updated: 2016/05/10 12:02:45 by dsusheno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

DIR_H = ./includes/

DIR_C = ./src/

DIR_O = ./objs/

FILE_C = main.c\
		 fractal.c\
		 mouse_key.c\
		 image.c

FILE_O = $(FILE_C:.c=.o)

SRC_C := $(addprefix $(DIR_C), $(FILE_C))

SRC_O := $(addprefix $(DIR_O), $(FILE_O))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	@clang -o $(NAME) $(SRC_O) libmlx.a -L libft/ -lft -framework OpenGL -framework AppKit

$(SRC_O): $(SRC_C)
	@make -C libft/
	@clang $(FLAGS) -c $(SRC_C) -I $(DIR_H)
	@mkdir -p $(DIR_O)
	@mv $(FILE_O) $(DIR_O)

clean:
	@/bin/rm -rf $(DIR_O)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: clean fclean all re
