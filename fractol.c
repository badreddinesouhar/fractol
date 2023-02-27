/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:38:40 by bsouhar           #+#    #+#             */
/*   Updated: 2023/02/26 09:44:34 by bsouhar          ###   ########.fr       */
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
// 	double c_img;
// 	double c_re;
// } t_mlx;

// typedef struct s_data
// {
// 	char *addr;
// 	int bits_per_pixel;
// 	int line_length;
// 	int endian;
// } t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
// static t_data ft_mlx_init_fractol(t_mlx *mlx)
// {
// 	t_data data;

// 	mlx->width = W;
// 	mlx->height = H;
// 	mlx->ptr = mlx_init();
// 	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "mandelbrot");
// 	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
// 	data.addr = mlx_get_data_addr(mlx->img, &(data.bits_per_pixel), &(data.line_length), &(data.endian));
// 	return (data);
// }

int main(int argc, char *argv[])
{
	t_mlx mlx;

	if(argc == 2 && atoi(argv[1]) == 1)
		mandelbrot(&mlx);
	else if(argc == 4 && atoi(argv[1]) == 2)
	{
		mlx.c_img = (double )atof(argv[2]);
		mlx.c_re = (double )atof(argv[3]);
		julia(&mlx);
	}
	mlx_loop(mlx.ptr);
}
