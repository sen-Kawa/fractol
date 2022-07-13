/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/13 11:53:13 by kaheinz          ###   ########.fr       */
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

void	julia(int argc, t_data *data)
{
	if (argc == 2)
		square(data, 10, 10);
}

void	mandelbrot_init(t_data *data)
{
	data->scale.max_x = 1;
	data->scale.min_x = -2;
//	data->scale.max_y = 2;
	data->scale.min_y = -1.5;
	data->scale.max_y = data->scale.min_y + (data->scale.max_x - data->scale.min_x) * WIN_HEIGHT / WIN_WIDTH;
}

void	mandelbrot(t_data *data)
{
	t_complex	c;
	int	iter;
	int	x;
	int	y;
	
	iter = 0;
	x = 0;
	y = 0;
	while (y < 1080)
	{
		c = pixel_to_complex(x, y, data);
		iter = mandelbrot_iteration(&c);
	//	if (iter == 100)
	//		my_mlx_pixel_put(data, x, y, BABYBLUE);
		if (iter < 100 && iter >= 75)
			my_mlx_pixel_put(data, x, y, RED);
		else if (iter < 75 && iter >= 25)
			my_mlx_pixel_put(data, x, y, BABYBLUE);
		else if (iter < 25 && iter >= 20)
			my_mlx_pixel_put(data, x, y, CORIANDER);
		else if (iter < 20 && iter >= 15)
			my_mlx_pixel_put(data, x, y, JUNGLE);
		else if (iter < 15 && iter >= 5)
			my_mlx_pixel_put(data, x, y, BLOSSOM);
		else if (iter < 5)
			my_mlx_pixel_put(data, x, y, LILAC);
		x++;
		if (x == WIN_WIDTH)
		{
			x = 0;
			y++;
		}
	}
}

int	mandelbrot_iteration(t_complex *c)
{
	int	iter;
	t_complex	m;

	iter = 0;
	m.i = 0.0;
	m.r = 0.0;
	while (absolute_complex(m) <= 2 && iter < MAX_ITER)
	{
		m = add_complex(mult_complex(m, m), c);
		iter++;
	}
	return (iter);
}

double	absolute_complex(t_complex c)
{
	return (sqrt((pow(c.i, 2)) + (pow(c.r, 2))));
}

t_complex	add_complex(t_complex m, t_complex *c)
{
	t_complex	a;

	a.r = m.r + c->r;
	a.i = m.i + c->i;
	return (a);
}

t_complex	mult_complex(t_complex m, t_complex c)
{
	t_complex	a;

	a.r = (m.r * c.r) - (m.i * c.i);
	a.i = (m.r * c.i) + (m.i * c.r);
	return (a);
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
