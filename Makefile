# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 18:56:29 by kaheinz           #+#    #+#              #
#    Updated: 2022/07/07 00:13:23 by kaheinz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

//INCLUDE = push_swap.h

SRCS = main.c\

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

$(NAME): $(OBJS)
	make -C libft/
	make -C mlx/
	make bonus -C libft/
	$(CC) $(CFLAGS) mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT)

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
