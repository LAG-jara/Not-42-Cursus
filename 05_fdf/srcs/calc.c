/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:13:20 by cwan              #+#    #+#             */
/*   Updated: 2024/04/25 19:14:55 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	maxz(int **map)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = map[0][0];
	while (map[i])
	{
		j = 0;
		while (map[i][j] != -999)
		{
			if (map[i][j] > z)
				z = map[i][j];
			j++;	
		}
		i++;
	}
	return (z);
}

int	numheight(int **map)
{
	int	y;
	
	y = 0;
	while (map[y++])
		;
	return (y);
}

int	numwidth(int **map)
{
	int	x;

	x = 0;
	while (map[0][x] != -999)
		x++;
	return (x);
}

int	calcww(int **map)
{
	return((int)ceil(numheight(map) * 20));
}

int	calcwh(int **map)
{
	return((int)ceil(numwidth(map)) * 20 * (1 + maxz(map) / (2 * numheight(map))));
}

void	drawline(t_mlx *fdf, int x1, int y1, int x2, int y2)
{
	int	dx = x2 - x1;
	int dy = y2 - y1;
	int	steps = ft_abs(dx) > ft_abs(dy) ? abs(dx) : abs(dy);
	float	x_inc = (float) dx / steps;
	float 	y_inc = (float) dy / steps;

	float x = x1;
	float y = y1;

	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(fdf->ptr, fdf->win, (int)round(x), (int)round(y), 0xFFFFFF);
		x += x_inc;
		y += y_inc;
	}
}
