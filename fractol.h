/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:57:35 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/08 08:54:28 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//Window size
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

//Keys
# define ESC 53

//Colours
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define BABYBLUE 0x0000FFFF


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "mlx/mlx.h"

typedef struct s_data
{
    void    *img;
    void    *mlx;
    void    *mlx_win;
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
void	controls(t_data *data);
int		close_win(void *param);
int		key_press(int keycode, void *param);

#endif
