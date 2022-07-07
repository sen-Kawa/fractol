/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:36:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/07 13:43:39 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx/mlx.h"

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
    t_data	img;
	int		line_x;
	int		line_y;

	line_x = 10;
	line_y = 10;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (line_x < 100)
	{
		if (line_x == 10 || line_x == 99)
		{
			while (line_y < 99)
			{
				my_mlx_pixel_put(&img, line_x, line_y, 0x0000FFFF);
				line_y++;
			}
		}
		my_mlx_pixel_put(&img, line_x, line_y, 0x0000FFFF);
		line_x++;
	}	
	while (line_x > 10)
	{
		if (line_y == 10 || line_y == 99)
		{
			while (line_y > 10)
			{
				my_mlx_pixel_put(&img, line_x, line_y, 0x0000FFFF);
				line_y--;
			}
		}
		my_mlx_pixel_put(&img, line_x, line_y, 0x0000FFFF);
		line_x--;
	}	
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    return (0);
}

