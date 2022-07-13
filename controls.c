/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:42:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/13 17:01:28 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	controls(t_data *data)
{
	mlx_hook(data->mlx_win, RED_CROSS, 0, close_win, data);
	mlx_hook(data->mlx_win, KEY_PRESS, 0, key_press, data);
//	mlx_hook(data->mlx_win, MOUSE_MOVE, 0, key_press, data);
}
/*
int	mouse_move(int x, int y, void *param)
{

}*/

int	key_press(int keycode, void *param)
{
	t_data *fractol;
	double subs_x;
	double subs_y;

	fractol = (t_data *)param;
	subs_x = (fractol->scale.max_x - fractol->scale.min_x);
	subs_y = (fractol->scale.max_y - fractol->scale.min_y);

	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == ARROW_RIGHT)
	{
		fractol->scale.min_x += subs_x * DISTANCE;
		fractol->scale.max_x += subs_x * DISTANCE;
		mandelbrot(fractol);
		mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
	}
	else if (keycode == ARROW_LEFT)
	{
		fractol->scale.min_x -= subs_x * DISTANCE;
		fractol->scale.max_x -= subs_x * DISTANCE;
		mandelbrot(fractol);
		mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
	}
	else if (keycode == ARROW_DWN)
	{
		fractol->scale.min_y += subs_y * DISTANCE;
		fractol->scale.max_y += subs_y * DISTANCE;
		mandelbrot(fractol);
		mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
	}
	else if (keycode == ARROW_UP)
	{
		fractol->scale.min_y -= subs_y * DISTANCE;
		fractol->scale.max_y -= subs_y * DISTANCE;
		mandelbrot(fractol);
		mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
	}
	else if (keycode == ZOOM_IN)
	{
		fractol->scale.min_x = fractol->scale.max_x + ZOOM_IN_VAL * (fractol->scale.min_x - fractol->scale.max_x);
		fractol->scale.max_x = fractol->scale.max_x + ((fractol->scale.min_x - fractol->scale.max_x) - ZOOM_IN_VAL * (fractol->scale.min_x - fractol->scale.max_x)) / 2;
		fractol->scale.min_y = fractol->scale.max_y + ZOOM_IN_VAL * (fractol->scale.min_y - fractol->scale.max_y);
		fractol->scale.max_y = fractol->scale.max_y + ((fractol->scale.min_y - fractol->scale.max_y) - ZOOM_IN_VAL * (fractol->scale.min_y - fractol->scale.max_y)) / 2;
		mandelbrot(fractol);
		mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
	}
	else if (keycode == ZOOM_OUT)
	{
		fractol->scale.min_x = fractol->scale.max_x + ZOOM_OUT_VAL * (fractol->scale.min_x - fractol->scale.max_x);
		fractol->scale.max_x = fractol->scale.max_x + ((fractol->scale.min_x - fractol->scale.max_x) - ZOOM_OUT_VAL * (fractol->scale.min_x - fractol->scale.max_x)) / 2;
		fractol->scale.min_y = fractol->scale.max_y + ZOOM_OUT_VAL * (fractol->scale.min_y - fractol->scale.max_y);
		fractol->scale.max_y = fractol->scale.max_y + ((fractol->scale.min_y - fractol->scale.max_y) - ZOOM_OUT_VAL * (fractol->scale.min_y - fractol->scale.max_y)) / 2;
		mandelbrot(fractol);
		mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
	}
	return (0);
}

int	close_win(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
