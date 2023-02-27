/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:38:00 by bsouhar           #+#    #+#             */
/*   Updated: 2023/02/25 18:03:56 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
t_data ft_mlx_init(t_mlx *mlx)
{
	t_data data;

	mlx->width = 1000;
	mlx->height = 1000;
	mlx->color = 0xAAFFFFFF;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "mandelbrot");
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	data.addr = mlx_get_data_addr(mlx->img, &(data.bits_per_pixel), &(data.line_length), &(data.endian));
	return (data);
}*/
