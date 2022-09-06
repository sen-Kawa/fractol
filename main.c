/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/09/06 17:03:38 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	arg_handling(int argc, char **argv, t_data *f)
{
	if (argc == 1)
	{
		ft_printf("Please add the set to display: Julia or Mandelbrot.\n");
		exit (EXIT_FAILURE);
	}
	if (argc >= 2)
	{
		if ((ft_strncmp(argv[1], "Julia", 6)) == 0)
	//		julia(argc, );
			draw_fractal(f);
		else if ((ft_strncmp(argv[1], "Mandelbrot", 11)) == 0)
	//		mandelbrot(data);
			draw_fractal(f);
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
int    print_key(int keycode, t_data *data)
{
    (void)data;
    ft_printf("This is the keycode:%i", keycode);
    return 0;
}

int	main(int argc, char **argv)
{
	t_data	f;

	f.mlx = mlx_init();
	f.mlx_win = mlx_new_window(f.mlx, WIN_WIDTH, WIN_HEIGHT, "FractOl!");
	f.img = mlx_new_image(f.mlx, WIN_WIDTH, WIN_HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bits_per_pixel, &f.line_length, &f.endian);
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * WIN_HEIGHT / WIN_WIDTH;
	arg_handling(argc, argv, &f);
	mlx_put_image_to_window(f.mlx, f.mlx_win, f.img, 0, 0);
	controls(&f);
	mlx_loop(f.mlx);
	return (0);
}
