/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/11 19:15:16 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	square(t_data *data, int line_x, int line_y)
{
	while (line_y <= 100)
	{
		while (line_x <= 100)
		{
			if ((line_y == 10 || line_y == 100)
				|| (line_x == 10 || line_x == 100))
				my_mlx_pixel_put(data, line_x, line_y, BABYBLUE);
			line_x++;
		}
		line_x = 10;
		line_y++;
	}
}

void	circle(t_data *data)
{
	int		center_x;
	int		center_y;
	int		radius_len;
	int		radius;

	center_x = 500;
	center_y = 500;
	radius_len = 50;
	radius = 0;
	my_mlx_pixel_put(data, center_x, center_y, GREEN);
	while (radius <= radius_len)
	{
		my_mlx_pixel_put(data, center_x, center_y, GREEN);
		center_x++;
		radius++;
	}
}

void	julia(int argc, t_data *data)
{
	if (argc == 2)
		square(data, 10, 10);
//	else if (argc == 4)
//		square(data, ft_atoi(), 10);
}

void	mandelbrot_init(t_data *data)
{
	data->scale.max_x = 2;
	data->scale.min_x = -2;
	data->scale.max_y = 2;
	data->scale.min_y = -2;
}

void	mandelbrot(t_data *data)
{
//	circle(data);
	t_complex	c;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 1080)
	{
		c = pixel_to_complex(x, y, data);
		if (c.i == 0 && c.r == 0)
		{
			my_mlx_pixel_put(data, x, y, BABYBLUE);
		}
		x++;
		if (x == WIN_WIDTH)
		{
			x = 0;
			y++;
		}
	}
}

void	test(t_data *data)
{
	t_complex	c;
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (c.i < 1)
	{
		c = pixel_to_complex(x, y, data);
		my_mlx_pixel_put(data, x, y, BABYBLUE);
		if (x == 960)
		{
			x = 0;
			y++;
		}
		x++;
	}
}

t_complex	pixel_to_complex(int x, int y, t_data *data)
{
	t_complex	comp;
	int	range_x;
	int	range_y;

	(void) data;
	range_x = data->scale.max_x - data->scale.min_x;
	range_y = data->scale.max_y - data->scale.min_y;
	comp.r = data->scale.min_x + (((float)x * range_x) / (WIN_WIDTH));
	comp.i = data->scale.min_y + (((float)y * range_y) / (WIN_HEIGHT));
	return (comp);
}
