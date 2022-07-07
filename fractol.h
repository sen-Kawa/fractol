/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:57:35 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/07 18:14:11 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "mlx/mlx.h"

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

typedef struct s_rect
{
    int     x;
    int     y;
    int     width;
    int     height;
    int     color;
}   t_rect;

void    circle(t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    square(t_data *data, int line_x, int line_y);
int		arg_handling(int argc, char **argv);

#endif