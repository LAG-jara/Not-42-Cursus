/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/05/02 14:33:53 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
void	drawstrline(t_mlx *fdf, int beginX, int beginY, int endX, int endY);

void	drawstuff(t_mlx *fdf, int **map)
{
	int		x;
	int		y;
	int		z;

	y = 0;
	fdf->theta = 30 * M_PI / 180;
	if (fdf->rows < fdf->cols)
		fdf->scale = ((double)800 / fdf->rows) / 2;
	else
		fdf->scale = ((double)800 / fdf->cols) / 2;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			z = map[y][x];
			fdf->x_rot = x * cos(fdf->theta) - y * sin(fdf->theta) * 0.7;
			fdf->y_rot = x * sin(fdf->theta) + y * cos(fdf->theta) * 0.7 - (z * 0.2);
			if (x + 1 < fdf->cols)
			{
				z = map[y][x + 1];
				fdf->x_rotnext = (x + 1) * cos(fdf->theta) - y * sin(fdf->theta) * 0.7;
				fdf->y_rotnext = (x + 1) * sin(fdf->theta) + y * cos(fdf->theta) * 0.7 - (z * 0.2);
				drawstrline(fdf, fdf->x_rot * fdf->scale + 200, fdf->y_rot * fdf->scale + 100, fdf->x_rotnext * fdf->scale + 200, fdf->y_rotnext * fdf->scale + 100);
			}
			if (y + 1 < fdf->rows)
			{
				z = map[y + 1][x];
				fdf->x_rotnext = x * cos(fdf->theta) - (y + 1) * sin(fdf->theta) * 0.7;
				fdf->y_rotnext = x * sin(fdf->theta) + (y + 1) * cos(fdf->theta) * 0.7 - (z * 0.2);
				drawstrline(fdf, fdf->x_rot * fdf->scale + 200, fdf->y_rot * fdf->scale + 100, fdf->x_rotnext * fdf->scale + 200, fdf->y_rotnext * fdf->scale + 100);
			}
//			mlx_pixel_put(fdf->ptr, fdf->win, fdf->x_rot * fdf->scale + 200, fdf->y_rot * fdf->scale + 100, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	drawstrline(t_mlx *fdf, int beginX, int beginY, int endX, int endY)
{
	double xd = endX - beginX;
	double yd = endY - beginY;
	int	pixels = sqrt((xd * xd) + (yd * yd));
	xd /= pixels;
	yd /= pixels;
	double pixelx = beginX;
	double pixely = beginY;
	while (pixels)
	{
		mlx_pixel_put(fdf->ptr, fdf->win, (int)pixelx, (int)pixely, 0xFFFFFF);
		pixelx += xd;
		pixely += yd;
		--pixels;
	}
}

int	main(int ac, char *av[])
{
	int		**map;
	t_mlx	*fdf;

	fdf = NULL;
	map = NULL;
	if (ac == 2)
	{
		fdf = initmlx(fdf, av[1]);
		map = intinput(av[1], fdf, map);
	}
	else
		return (0);
	drawstuff(fdf, map);
	mlx_key_hook(fdf->win, keyinput, fdf);
	mlx_loop(fdf->ptr);
	return (ft_freeint(map), 0);
}
