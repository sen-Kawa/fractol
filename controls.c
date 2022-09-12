/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:42:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/09/12 21:33:27 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	controls(t_data *f)
{
	mlx_key_hook(f->mlx_win, &print_key, &f->img);
	mlx_hook(f->mlx_win, RED_CROSS, 0, close_win, f);
	mlx_hook(f->mlx_win, KEY_PRESS, 1L<<0, key_press, f);
//	mlx_mouse_hook(f->mlx_win, mouse_hook, &f);
}
/*
int	mouse_move(int x, int y, void *param)
{

}*/

int	key_press(int keycode, void *param)
{
	t_data *f;
//	double subs_x;
//	double subs_y;

	f = (t_data *)param;
//	subs_x = (f->max_r - f->min_r);
//	subs_y = (f->max_i - f->min_i);

//	(void)keycode;
	(void)param;

	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == ARROW_RIGHT)
	{
		f->min_r += (f->max_r - f->min_r) * DISTANCE;
		f->max_r += (f->max_r - f->min_r) * DISTANCE;
		draw_fractal(f, 5);
		mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	}
	else if (keycode == ARROW_LEFT)
	{
		f->min_r -= (f->max_r - f->min_r) * DISTANCE;
		f->max_r -= (f->max_r - f->min_r) * DISTANCE;
		draw_fractal(f, 5);
		mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	}
	else if (keycode == ARROW_UP)
	{
		f->min_i += (f->max_i - f->min_i) * DISTANCE;
		f->max_i += (f->max_i - f->min_i) * DISTANCE;
		draw_fractal(f, 5);
		mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	}
	else if (keycode == ARROW_DWN)
	{
		f->min_i -= (f->max_i - f->min_i) * DISTANCE;
		f->max_i -= (f->max_i - f->min_i) * DISTANCE;
		draw_fractal(f, 5);
		mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	}
	else if (keycode == ZOOM_IN)
	{
		f->min_r = f->max_r + ZOOM_IN_VAL * (f->min_r - f->max_r);
		f->max_r = f->max_r + ((f->min_r - f->max_r) - ZOOM_IN_VAL * (f->min_r - f->max_r)) / 2;
		f->min_i = f->max_i + ZOOM_IN_VAL * (f->min_i - f->max_i);
		f->max_i = f->max_i + ((f->min_i - f->max_i) - ZOOM_IN_VAL * (f->min_i - f->max_i)) / 2;
		draw_fractal(f, 5);
		mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	}
	else if (keycode == ZOOM_OUT)
	{
		f->min_r = f->max_r + ZOOM_OUT_VAL * (f->min_r - f->max_r);
		f->max_r = f->max_r + ((f->min_r - f->max_r) - ZOOM_OUT_VAL * (f->min_r - f->max_r)) / 2;
		f->min_i = f->max_i + ZOOM_OUT_VAL * (f->min_i - f->max_i);
		f->max_i = f->max_i + ((f->min_i - f->max_i) - ZOOM_OUT_VAL * (f->min_i - f->max_i)) / 2;
		draw_fractal(f, 5);
		mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	}
	return (0);
}

int	close_win(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
