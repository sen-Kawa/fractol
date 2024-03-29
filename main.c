/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2023/01/27 22:33:52 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int n)
{
	char	*dst;
	int		colour;

	dst = data->addr + (data->y * data->line_len + data->x
			* (data->bit_per_pix / 8));
	colour = colour_trgb(0, data->r * (cos((double)n) + 1),
			80 * (sin((double)n) + 1),
			50 * (1 - cos((double)n)));
	*(unsigned int *)dst = colour;
}

int	two_args(int argc, char **argv, t_data *f)
{
	(void) argc;
	if ((ft_strncmp(argv[1], "Julia", 6)) == 0)
	{
		f->fractal = 4;
		draw_fractal(f);
	}	
	else if ((ft_strncmp(argv[1], "Mandelbrot", 11)) == 0)
	{
		f->fractal = 5;
		draw_fractal(f);
	}	
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
	return (0);
}

int	arg_handling(int argc, char **argv, t_data *f)
{
	if (argc == 1)
	{
		ft_printf("Please add the set to display: Julia or Mandelbrot.\n");
		exit (EXIT_FAILURE);
	}
	if (argc >= 2)
		two_args(argc, argv, f);
	return (0);
}

int	print_key(int keycode, t_data *data)
{
	(void)data;
	(void)keycode;
//	ft_printf("This is the keycode:%i", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*f;

	f = malloc(sizeof(t_data));
	f->mlx = mlx_init();
	f->mlx_win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "FractOl!");
	f->img = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bit_per_pix,
			&f->line_len, &f->endian);
	f->r = 100;
	f->min_r = -2.0;
	f->max_r = 1.0;
	f->min_i = -1.5;
	f->max_i = f->min_i + (f->max_r - f->min_r) * WIN_HEIGHT / WIN_WIDTH;
	f->kr = -0.766667;
	f->ki = -0.090000;
	arg_handling(argc, argv, f);
	controls(f);
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	mlx_loop(f->mlx);
	return (0);
}
