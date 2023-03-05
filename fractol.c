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

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	mlx.zoom = 4.0;
	if (argc == 2 && ft_atoi(argv[1]) == 1)
	{
		ft_mlx_init_fractol(&mlx);
		mlx.arg = 1;
		mandelbrot(&mlx);
	}
	else if (argc == 4 && ft_atoi(argv[1]) == 2)
	{
		ft_mlx_init_fractol(&mlx);
		mlx.arg = 2;
		mlx.c_img = ft_atof(argv[2]);
		mlx.c_re = ft_atof(argv[3]);
		julia(&mlx);
	}
	else if (argc == 2 && ft_atoi(argv[1]) == 3)
	{
		ft_mlx_init_fractol(&mlx);
		mlx.arg = 3;
		burning_ship(&mlx);
	}
	else 
		ft_error();
	mlx_loop(mlx.ptr);
}
