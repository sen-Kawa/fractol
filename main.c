/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/07 22:40:04 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	square(t_data *data, int line_x, int line_y)
{
	while (line_x < 100)
	{
		if (line_x == 10 || line_x == 99)
		{
			while (line_y < 99)
			{
				my_mlx_pixel_put(data, line_x, line_y, 0x0000FFFF);
				line_y++;
			}
		}
		my_mlx_pixel_put(data, line_x, line_y, 0x0000FFFF);
		line_x++;
	}	
	while (line_x > 10)
	{
		if (line_y == 10 || line_y == 99)
		{
			while (line_y > 10)
			{
				my_mlx_pixel_put(data, line_x, line_y, 0x0000FFFF);
				line_y--;
			}
		}
		my_mlx_pixel_put(data, line_x, line_y, 0x0000FFFF);
		line_x--;
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

	my_mlx_pixel_put(data, center_x, center_y, 0x00FF0000);
	while (radius <= radius_len)
	{
		my_mlx_pixel_put(data, center_x, center_y, 0x00FF0000);
		center_x++;
		radius++;
	}
}

int	arg_handling(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Please add as parameter the set you would like to display: Julia or Mandelbrot.\n");
		exit (EXIT_FAILURE);
	}
	if (argc == 2)
	{
		ft_printf("%s", argv[1]);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data	img;
	
	arg_handling(argc, argv);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FractOl!");
	img.img = mlx_new_image(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	square(&img, 10, 10);
	circle(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	controls(&img);
	mlx_loop(img.mlx);
	return (0);
}

