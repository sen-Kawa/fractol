/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:42:48 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/08 09:32:15 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	controls(t_data *data)
{
	mlx_hook(data->mlx_win, RED_CROSS, 0, close_win, data);
	mlx_hook(data->mlx_win, KEY_PRESS, 0, key_press, data);
//	mlx_hook(data->mlx_win, MOUSE_MOVE, 0, key_press, data);
}
/*
int	mouse_move(int x, int y, void *param)
{

}*/

int	key_press(int keycode, void *param)
{
	t_data *fractol;
	
	fractol = (t_data *)param;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int	close_win(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
