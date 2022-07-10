/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/10 11:48:50 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
		else if ((ft_strncmp(argv[1], "test", 5)) == 0)
			test(data);
		else if ((ft_strncmp(argv[1], "--help", 7)) == 0)
		{
			ft_printf("Fractals available: Julia or Mandelbrot.\n");
			exit (EXIT_FAILURE);
		}
		else
		{
			ft_printf("Please pass either Julia or Mandelbrot. Try again :)\n");
			exit (EXIT_FAILURE);
		}
	}
	return (0);
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
