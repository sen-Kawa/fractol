/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/09/27 15:07:13 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_data *f)
{
	double	pr;
	double	pi;
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIN_WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / WIN_HEIGHT;
			if (f->fractal == 4)
				julia(f, x, y, pr, pi);
			else if (f->fractal == 5)
				mandelbrot(f, x, y, pr, pi);
		}
	}
}

void	mandelbrot(t_data *f, int x, int y, double cr, double ci)
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
	my_mlx_pixel_put(f, x, y, n);
}

void	julia(t_data *f, int x, int y, double zr, double zi)
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
	my_mlx_pixel_put(f, x, y, n);
}
