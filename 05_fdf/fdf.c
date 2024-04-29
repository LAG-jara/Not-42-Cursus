/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/04/30 04:33:06 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawstuff(t_mlx *fdf, int **map)
{
	int		x;
	int		y;
	double	x_rot;
	double	y_rot;
	double	theta;
	int		z;

	y = 0;
	theta = 30 * M_PI / 180;
	while (map[y])
	{
		x = 0;
		while (x < fdf->cols)
		{
			z = map[y][x];
			x_rot = x * cos(theta) - y * sin(theta) * 0.7;
			y_rot = x * sin(theta) + y * cos(theta) * 0.7 - (z * 0.5);
			mlx_pixel_put(fdf->ptr, fdf->win, x_rot * 10 + 50, \
			y_rot * 10 + 50, 0xFFFFFF);
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
	double pixelx = 100;
	double pixely = 100;
	while (pixels)
	{
		mlx_pixel_put(fdf->ptr, fdf->win, pixelx, pixely, 0xFFFFFF);
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
	drawstrline(fdf, 10, 10, 100, 100);
	mlx_key_hook(fdf->win, keyinput, fdf);
	mlx_loop(fdf->ptr);
	return (ft_freeint(map), 0);
}
