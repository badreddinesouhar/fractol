/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:34:50 by bsouhar           #+#    #+#             */
/*   Updated: 2023/02/25 16:30:18 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	int		width;
	int		height;
	int		color;
	double	c_img;
	double	c_re;
	double	z_re;
	double	z_img;
	double	all;
	double	x;
	double	y;
	int		i;
	int		max_iterations;
}			t_mlx;

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_draw(t_mlx *mlx);
t_data		ft_mlx_init_fractol(t_mlx *mlx);
//  static t_data ft_mlx_init_fractol(t_mlx *mlx);
void		julia(t_mlx *mlx);
void		mandelbrot(t_mlx *mlx);

#endif
