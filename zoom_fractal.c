/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:49:14 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/05 21:49:18 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_in(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->zoom *= 1.1;
	if (mlx->arg == 1)
		mandelbrot(mlx);
	else if (mlx->arg == 2)
		julia(mlx);
	else if (mlx->arg == 3)
		burning_ship(mlx);
	return (0);
}

int	zoom_out(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->zoom /= 1.1;
	if (mlx->arg == 1)
		mandelbrot(mlx);
	else if (mlx->arg == 2)
		julia(mlx);
	else if (mlx->arg == 3)
		burning_ship(mlx);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == 4)
		zoom_out(mlx);
	else if (key == 5)
		zoom_in(mlx);
	return (0);
}
