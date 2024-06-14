# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 20:33:51 by zaldhahe          #+#    #+#              #
#    Updated: 2024/06/14 16:18:46 by zaldhahe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c arguments.c mandelbrot.c hooks.c julia.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra 
MLX = minilibx_opengl_20191021

LIBFT = Libft

LINK = -lmlx -framework OpenGL -framework AppKit -L$(MLX)

COMPILE = $(CC) $(CFLAGS) $(LINK)

all : $(NAME)

$(NAME) : $(OBJ)
	$(COMPILE) $(OBJ) $(LIBFT)/libft.a -o $(NAME)

$(MLX)/libmlx.a:
	$(MAKE) -C $(MLX)

$(LIBFT)/libft.a:
	$(MAKE) -C $(MLX)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
