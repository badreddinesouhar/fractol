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

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc == 2 && atoi(argv[1]) == 1)
		mandelbrot(&mlx);
	else if (argc == 4 && atoi(argv[1]) == 2)
	{
		mlx.c_img = (double)atof(argv[2]);
		mlx.c_re = (double)atof(argv[3]);
		julia(&mlx);
	}
	mlx_loop(mlx.ptr);
}
