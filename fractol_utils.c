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

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_handler(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(0);
	}
	return (0);
}

int	ft_draw(t_mlx *mlx)
{
	double	z_re2;
	double	z_img2;

	while (mlx->all < 4 && mlx->i < mlx->max_iterations)
	{
		z_re2 = mlx->z_re * mlx->z_re;
		z_img2 = mlx->z_img * mlx->z_img;
		mlx->z_img = 2 * mlx->z_img * mlx->z_re + mlx->c_img;
		mlx->z_re = z_re2 - z_img2 + mlx->c_re;
		mlx->all = mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img;
		mlx->i++;
	}
	return (mlx->i);
}

void	ft_mlx_init_fractol(t_mlx *mlx)
{
	mlx->w = 1000;
	mlx->h = 1000;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->w, mlx->h, "julia");
	mlx_key_hook(mlx->win, key_handler, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
}
