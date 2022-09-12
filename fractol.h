/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:57:35 by kaheinz           #+#    #+#             */
/*   Updated: 2022/09/12 23:32:56 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// Window size
# define WIN_WIDTH 900
# define WIN_HEIGHT 900

// Zoom and Movement
# define DISTANCE 0.05
# define ZOOM_OUT_VAL 2
# define ZOOM_IN_VAL 0.5

// Events
# define KEY_PRESS 2
# define RED_CROSS 17
# define MOUSE_MOVE 6

// Keys
#if __linux__

# define ESC 65307
# define ZOOM_IN 105
# define ZOOM_OUT 111
# define ARROW_UP 65362
# define ARROW_DWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define SCROLL_DOWN 4
# define SCROLL_UP 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define MIDDLE_CLICK 2


#elif __APPLE__

# define ESC 53
# define ZOOM_IN 34
# define ZOOM_OUT 31
# define ARROW_UP 126
# define ARROW_DWN 125
# define ARROW_LEFT 123
# define SCROLL_DOWN 5
# define SCROLL_UP 4
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3

# define ARROW_RIGHT 124

#endif

//Colours
# define RED 0x00FF0000
# define BLACK 0x00000000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define BABYBLUE 0x0000FFFF
# define LILAC 0x00C5A2C5
# define JUNGLE 0x00A7CBD0
# define CORIANDER 0x00BDCCAC
# define BLOSSOM 0x00DBBAC1

# define MAX_ITER_MANDEL 80
# define MAX_ITER_JULIA 10

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <X11/keysym.h>
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

typedef struct s_data
{
    void    *img;
    void    *mlx;
    void    *mlx_win;
    char    *addr;
    int     bit_per_pix; //used in my_mlx_pixel_put
    int     line_len; //used in my_mlx_pixel_put
    int     endian; //used in mlx_get_data_addrr in main
	double	max_r;
	double	min_r;
	double	max_i;
	double	min_i;
	double	kr;
	double	ki;
}   t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	controls(t_data *f);
void	mandelbrot(t_data *f, int x, int y, double cr, double ci);
void	julia(t_data *f, int x, int y, double zr, double zi);
void	draw_fractal(t_data *f, int n);
int     mouse_down(int button, int x, int y, void *param);
int     mouse_move(int x, int y, void *param);
int		arg_handling(int argc, char **argv, t_data *data);
int		close_win(void *param);
int		key_press(int keycode, void *param);
int		print_key(int keycode, t_data *data);

#endif
