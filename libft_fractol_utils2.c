/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fractol_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:28:28 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/09 23:29:33 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_fraction(const char *str, int *index, int *div)
{
	double	res;
	int		i;

	res = 0.0;
	i = *index;
	*div = 1;
	while (ft_isdigit(str[i]))
	{
		res = res * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			res = res * 10.0 + (str[i] - '0');
			*div *= 10;
			i++;
		}
	}
	*index = i;
	return (res);
}

static int	get_sign(const char *str, int *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			sign = -1;
		(*index)++;
	}
	return (sign);
}

double	ft_atof(const char *str)
{
	int		i;
	double	sign;
	double	res;
	int		div;

	i = 0;
	sign = 1.0;
	res = 0.0;
	div = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = get_sign(str, &i);
	res = parse_fraction(str, &i, &div);
	return (sign * res / div);
}
