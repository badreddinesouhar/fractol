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


// typedef struct s_mlx
// {
// 	void *ptr;
// 	void *win;
// 	void *img;
// 	int width;
// 	int height;
// 	int color;
// } t_mlx;

// typedef struct s_data
// {
// 	char *addr;
// 	int bits_per_pixel;
// 	int line_length;
// 	int endian;
// } t_data;

static t_data ft_mlx_init_fractol(t_mlx *mlx);

static void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
void mandelbrot(t_mlx *mlx){
	double z_re, z_img, c_re, c_img, all, x, y;
	int i;
	int max_iterations = 1500;
	x = 0;
	t_data data;
	data = ft_mlx_init_fractol(mlx);

	while (x < 1000)
	{
		y = 0;

		while (y < 1000)
		
		{
			c_re = (x - W / 2.0) * (4.0 / W);
			c_img = (y - W / 2.0) * (4.0 / W);
			z_img = 0;
			z_re = 0;

			all = z_re * z_re + z_img * z_img;
			i = 0;

			while (all < 4 && i < max_iterations)
			{
				double z_re2 = z_re * z_re;
				double z_img2 = z_img * z_img;

				z_img = 2 * z_img * z_re + c_img;
				z_re = z_re2 - z_img2 + c_re;
				all = z_re * z_re +z_img * z_img;
				i++;
			}
			// double color = i % 16 * 0xE12700 + i % 16 * 0xC7D0D1+ i % 16 * 0x484848 ;
			// // double color2 = i % 16 * 0x000000+ i % 16 * 0x7B8181+ i % 16 * 0xF9FEFF;
		   	
			// if(i < 5)
			// 	my_mlx_pixel_put(&data, x, y, 0x000000);
			// if(i < 15)
			// 	my_mlx_pixel_put(&data, x, y, color);
			// else if (i < 50)
				// my_mlx_pixel_put(&data, x, y, 0xFFFFFF);
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
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "mandelbrot");
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	data.addr = mlx_get_data_addr(mlx->img, &(data.bits_per_pixel), &(data.line_length), &(data.endian));
	return (data);
}
// int main()
// {
// 	t_mlx mlx;
	
// 	mandelbrot(&mlx);
	
// 	mlx_loop(mlx.ptr);
// }
