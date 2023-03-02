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

#define W 1000
#define H 1000

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

t_data	ft_mlx_init_fractol(t_mlx *mlx)
{
	t_data	data;

	mlx->width = W;
	mlx->height = H;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "julia");
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	data.addr = mlx_get_data_addr(mlx->img, &(data.bits_per_pixel),
			&(data.line_length), &(data.endian));
	return (data);
}
