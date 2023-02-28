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


static t_data ft_mlx_init_fractol(t_mlx *mlx);

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

static void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void julia(t_mlx *mlx){
	double z_re, z_img, all, x, y;
	int i;
	int max_iterations = 50;
	x = 0;
	t_data data;
	data = ft_mlx_init_fractol(mlx);

	while (x < 1000)
	{
		y = 0;

		while (y < 1000)
		
		{
			z_re = (x - W / 2.0) * (4.0 / W);
			z_img = (y - W / 2.0) * (4.0 / W);

			all = z_re * z_re + z_img * z_img;
			i = 0;

			while (all < 4 && i < max_iterations)
			{
				double z_re2 = z_re * z_re;
				double z_img2 = z_img * z_img;

				z_img = 2 * z_img * z_re + mlx->c_img;
				z_re = z_re2 - z_img2 + mlx->c_re;
				all = z_re * z_re +z_img * z_img;
				i++;
			}
				double color  = i % 16 * 0x000000 + i % 16 * 0xECEEF1 + i % 16 * 0x242322;
            if (i == max_iterations)
                my_mlx_pixel_put(&data, x, y, 0x000000);
            else
                my_mlx_pixel_put(&data, x, y, color);
			y++;			
		}
		x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	
}

static t_data ft_mlx_init_fractol(t_mlx *mlx)
{
	t_data data;

	mlx->width = W;
	mlx->height = H;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "julia");
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	data.addr = mlx_get_data_addr(mlx->img, &(data.bits_per_pixel), &(data.line_length), &(data.endian));
	return (data);
}
