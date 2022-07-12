/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:57:35 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/12 13:52:38 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//Window size
# define WIN_WIDTH 1080
# define WIN_HEIGHT 1080

//Events
# define RED_CROSS 17
# define KEY_PRESS 2
# define MOUSE_MOVE 6

//Keys
# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5


//Colours
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define BABYBLUE 0x0000FFFF
# define LILAC 0x00C5A2C5
# define JUNGLE 0x00A7CBD0
# define CORIANDER 0x00BDCCAC
# define BLOSSOM 0x00DBBAC1

# define MAX_ITER 100

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "mlx/mlx.h"

typedef struct	s_scale
{
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
}	t_scale;

typedef struct s_data
{
    void    *img;
    void    *mlx;
    void    *mlx_win;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
	t_scale	scale;
}   t_data;

typedef struct	s_complex
{
	double	r;
	double	i;
}	t_complex;

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
int		arg_handling(int argc, char **argv, t_data *data);
void	controls(t_data *data);
int		close_win(void *param);
int		key_press(int keycode, void *param);
void	julia(int argc, t_data *data);
void	mandelbrot_init(t_data *data);
void	mandelbrot(t_data *data);
t_complex	pixel_to_complex(int x, int y, t_data *data);
void	test(t_data *data);
t_complex	add_complex(t_complex m, t_complex *c);
t_complex	mult_complex(t_complex m, t_complex c);
double	absolute_complex(t_complex c);
int	mandelbrot_iteration(t_complex *c);

#endif
