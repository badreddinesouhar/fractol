/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:27:55 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/05 19:27:58 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	ft_map_init_burning_ship(t_mlx *mlx)
{
	mlx->c_re = (mlx->x - mlx->w / 2.0) * (mlx->zoom / mlx->w);
	mlx->c_img = (mlx->y - mlx->h / 2.0) * (mlx->zoom / mlx->h);
	mlx->z_img = 0;
	mlx->z_re = 0;
	mlx->all = mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img;
	mlx->i = 0;
}

int	ft_draw_burning_ship(t_mlx *mlx)
{
	double	z_re2;
	double	z_img2;

	while (mlx->all < 4 && mlx->i < mlx->max_iterations)
	{
		z_re2 = mlx->z_re * mlx->z_re;
		z_img2 = mlx->z_img * mlx->z_img;
		mlx->z_img = fabs(2 * mlx->z_re * mlx->z_img) + mlx->c_img;
		mlx->z_re = z_re2 - z_img2 + mlx->c_re;
		mlx->all = mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img;
		mlx->i++;
	}
	return (mlx->i);
}

void	burning_ship(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, mlx->w, mlx->h);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
			&(mlx->line_length), &(mlx->endian));
	mlx->max_iterations = 250;
	mlx->x = 0;
	while (mlx->x < mlx->w)
	{
		mlx->y = 0;
		while (mlx->y < mlx->h)
		{
			ft_map_init_burning_ship(mlx);
			ft_draw_burning_ship(mlx);
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
