# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 18:56:29 by kaheinz           #+#    #+#              #
#    Updated: 2022/09/13 00:23:27 by kaheinz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c controls.c mouse_controls.c fractals.c\

LIBFT = libft/libft.a

#OS = $(shell uname -s)

#ifeq ($(OS), Darwin)
#LIBS = mlx/libmlx.a -framework OpenGL -framework AppKit
#LIBMLX = ./mlx
#else
#LIBS = mlx-linux/libmlx.a -lXext -lX11 -lm -lz
#LIBMLX = ./mlx-linux
#endif

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g -fsanitize=address

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	make -C libft/
#	$(MAKE) -C $(LIBMLX)
	make bonus -C libft/
	$(CC) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(OBJS) $(LIBFT) mlx_linux/libmlx.a

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C libft/
	make clean -C mlx/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
