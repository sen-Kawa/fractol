/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/09/27 16:41:42 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_data *f)
{
	double	pr;
	double	pi;

	f->y = -1;
	while (++f->y < WIN_HEIGHT)
	{
		f->x = -1;
		while (++f->x < WIN_WIDTH)
		{
			pr = f->min_r + (double)f->x * (f->max_r - f->min_r) / WIN_WIDTH;
			pi = f->max_i + (double)f->y * (f->min_i - f->max_i) / WIN_HEIGHT;
			if (f->fractal == 4)
				julia(f, pr, pi);
			else if (f->fractal == 5)
				mandelbrot(f, pr, pi);
		}
	}
}

void	mandelbrot(t_data *f, double cr, double ci)
{
	double	zr;
	double	zi;
	double	tmp;
	int		n;

	zr = 0;
	zi = 0;
	n = -1;
	while (++n < MAX_ITER_MANDEL)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	my_mlx_pixel_put(f, n);
}

void	julia(t_data *f, double zr, double zi)
{
	double	tmp;
	int		n;

	n = -1;
	while (n < MAX_ITER_JULIA)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ki;
		zr = zr * zr - zi * zi + f->kr;
		zi = tmp;
		n++;
	}
	my_mlx_pixel_put(f, n);
}
