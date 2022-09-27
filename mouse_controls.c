/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:42:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/09/27 15:14:31 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, void *param)
{
	t_data	*f;

	f = (t_data *)param;
	if (f->fractal == 4)
	{
		f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIN_WIDTH;
		f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / WIN_HEIGHT;
		draw_fractal(f);
		mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	}
	return (0);
}

int	mouse_down(int button, int x, int y, void *param)
{
	t_data	*f;

	f = (t_data *)param;
	(void) x;
	(void) y;
	if (button == SCROLL_UP)
	{
		f->min_r = f->max_r + ZOOM_IN_VAL * (f->min_r - f->max_r);
		f->max_r = f->max_r + ((f->min_r - f->max_r) - ZOOM_IN_VAL
				* (f->min_r - f->max_r)) / 2;
		f->min_i = f->max_i + ZOOM_IN_VAL * (f->min_i - f->max_i);
		f->max_i = f->max_i + ((f->min_i - f->max_i) - ZOOM_IN_VAL
				* (f->min_i - f->max_i)) / 2;
	}
	else if (button == SCROLL_DOWN)
	{
		f->min_r = f->max_r + ZOOM_OUT_VAL * (f->min_r - f->max_r);
		f->max_r = f->max_r + ((f->min_r - f->max_r) - ZOOM_OUT_VAL
				* (f->min_r - f->max_r)) / 2;
		f->min_i = f->max_i + ZOOM_OUT_VAL * (f->min_i - f->max_i);
		f->max_i = f->max_i + ((f->min_i - f->max_i) - ZOOM_OUT_VAL
				* (f->min_i - f->max_i)) / 2;
	}
	draw_fractal(f);
	return (mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0));
}
