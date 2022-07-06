# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 18:56:29 by kaheinz           #+#    #+#              #
#    Updated: 2022/07/06 23:41:03 by kaheinz          ###   ########.fr        #
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
	make bonus -C libft/
	$(CC) $(CFLAGS) mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
