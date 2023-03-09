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
	int		w;
	int		h;
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
	double	zoom;
	int		arg;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}			t_mlx;

void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int			ft_draw(t_mlx *mlx);
void		ft_mlx_init_fractol(t_mlx *mlx);
double		ft_atof(const char *str);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			mouse_hook(int key, int x, int y, t_mlx *mlx);
void		julia(t_mlx *mlx);
void		mandelbrot(t_mlx *mlx);
void		burning_ship(t_mlx *mlx);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);

#endif
