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

#define W 1000
#define H 1000

t_mlx	*ft_map_init_mandelbrot(t_mlx *mlx)
{
	mlx->c_re = (mlx->x - W / 2.0) * (4.0 / W);
	mlx->c_img = (mlx->y - W / 2.0) * (4.0 / W);
	mlx->z_img = 0;
	mlx->z_re = 0;
	mlx->all = mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img;
	mlx->i = 0;
	return (mlx);
}

void	mandelbrot(t_mlx *mlx)
{
	t_data	data;

	mlx->max_iterations = 1500;
	mlx->x = 0;
	data = ft_mlx_init_fractol(mlx);
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
				my_mlx_pixel_put(&data, mlx->x, mlx->y, 0x000000);
			else
				my_mlx_pixel_put(&data, mlx->x, mlx->y, mlx->color);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
