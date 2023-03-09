/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:05:19 by bsouhar           #+#    #+#             */
/*   Updated: 2023/02/25 18:03:12 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_map_init_mandelbrot(t_mlx *mlx)
{
	mlx->c_re = (mlx->x - mlx->w / 2.0) * (mlx->zoom / mlx->w);
	mlx->c_img = (mlx->y - mlx->w / 2.0) * (mlx->zoom / mlx->w);
	mlx->z_img = 0;
	mlx->z_re = 0;
	mlx->all = mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img;
	mlx->i = 0;
}

void	mandelbrot(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, mlx->w, mlx->h);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
			&(mlx->line_length), &(mlx->endian));
	mlx->max_iterations = 250;
	mlx->x = 0;
	while (mlx->x < 1000)
	{
		mlx->y = 0;
		while (mlx->y < 1000)
		{
			ft_map_init_mandelbrot(mlx);
			ft_draw(mlx);
			mlx->color = mlx->i % 16 * 0x000000 + mlx->i % 16 * 0xECEEF1
				+ mlx->i % 16 * 0x242322;
			if (mlx->i == mlx->max_iterations)
				my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x000000);
			else
				my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->color);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->ptr);
}
