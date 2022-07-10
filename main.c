/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/08 20:31:45 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

int	arg_handling(int argc, char **argv, t_data *data)
{
	if (argc == 1)
	{
		ft_printf("Please add the set to display: Julia or Mandelbrot.\n");
		exit (EXIT_FAILURE);
	}
	if (argc >= 2)
	{
		if ((ft_strncmp(argv[1], "Julia", 6)) == 0)
			julia(argc, data);
		else if ((ft_strncmp(argv[1], "Mandelbrot", 11)) == 0)
			mandelbrot(data);
		else
		{
			ft_printf("Please pass either Julia or Mandelbrot. Try again :)\n");
			exit (EXIT_FAILURE);
		}
	}
	return (0);
}

void	julia(int argc, t_data *data)
{
	if (argc == 2)
		square(data, 10, 10);
//	else if (argc == 4)
//		square(data, ft_atoi(), 10);
}

void	mandelbrot(t_data *data)
{
	circle(data);
}

void	pixel_to_complex()
{

}

int	main(int argc, char **argv)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HEIGHT, "FractOl!");
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	arg_handling(argc, argv, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	controls(&img);
	mlx_loop(img.mlx);
	return (0);
}
