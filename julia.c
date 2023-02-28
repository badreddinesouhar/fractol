/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:44:38 by bsouhar           #+#    #+#             */
/*   Updated: 2023/02/26 09:55:20 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define W 1000
#define H 1000

static t_data	ft_mlx_init_fractol(t_mlx *mlx);

// int	key_handler(int key, t_mlx *mlx)
// {
// 	//printf("key: %d\n",key);
// 	if (key == 53)
// 	{
// 		mlx_destroy_window(mlx->init, mlx->window);
// 		exit(0);
// 	}
// 	return(0);
// }

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	julia(t_mlx *mlx)
{
	t_data	data;
	double	z_re2;
	double	z_img2;

	mlx->max_iterations = 50;
	mlx->x = 0;
	data = ft_mlx_init_fractol(mlx);
	while (mlx->x < 1000)
	{
		mlx->y = 0;
		while (mlx->y < 1000)
		{
			mlx->z_re = (mlx->x - W / 2.0) * (4.0 / W);
			mlx->z_img = (mlx->y - W / 2.0) * (4.0 / W);
			mlx->all = mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img;
			mlx->i = 0;
			while (mlx->all < 4 && mlx->i < mlx->max_iterations)
			{
				z_re2 = mlx->z_re * mlx->z_re;
				z_img2 = mlx->z_img * mlx->z_img;
				mlx->z_img = 2 * mlx->z_img * mlx->z_re + mlx->c_img;
				mlx->z_re = z_re2 - z_img2 + mlx->c_re;
				mlx->all = mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img;
				mlx->i++;
			}
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

static t_data	ft_mlx_init_fractol(t_mlx *mlx)
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
