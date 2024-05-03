/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/05/03 13:47:41 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	drawline(t_mlx *fdf, int beginX, int beginY, int endX, int endY)
{
	double xd = endX - beginX;
	double yd = endY - beginY;
	int	pixels = sqrt((xd * xd) + (yd * yd));
	xd /= pixels;
	yd /= pixels;
	double pixelx = beginX;
	double pixely = beginY;
	int *image = (int *)fdf->data;

	while (pixels)
	{
		int index = ((int)pixely * fdf->size_line / 4) + (int)pixelx;
		image[index] = 0xFFFFFF;
		pixelx += xd;
		pixely += yd;
		--pixels;
	}
}

void	setxy(t_mlx *fdf, int x, int y)
{
	int z;

	z = fdf->map[y][x];
	fdf->x_rot = x * cos(fdf->theta) - y * sin(fdf->theta) * 0.7;
	fdf->y_rot = x * sin(fdf->theta) + y * cos(fdf->theta) * 0.7 - (z * 0.2);
}

void	setxyn(t_mlx *fdf, int x, int y)
{
	int	z;

	z = fdf->map[y][x];
	fdf->x_rotnext = x * cos(fdf->theta) - y * sin(fdf->theta) * 0.7;
	fdf->y_rotnext = x * sin(fdf->theta) + y * cos(fdf->theta) * 0.7 - (z * 0.2);
	drawline(fdf, fdf->x_rot * fdf->scale + 200, fdf->y_rot * fdf->scale + 100, fdf->x_rotnext * fdf->scale + 200, fdf->y_rotnext * fdf->scale + 100);
//	drawstrline(fdf, fdf->x_rot * fdf->scale + 200, fdf->y_rot * fdf->scale + 100, fdf->x_rotnext * fdf->scale + 200, fdf->y_rotnext * fdf->scale + 100);
}

void	drawstuff(t_mlx *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			setxy(fdf, x, y);
			if (x + 1 < fdf->cols)
				setxyn(fdf, x + 1, y);
			if (y + 1 < fdf->rows)
				setxyn(fdf, x, y + 1);
//			mlx_pixel_put(fdf->ptr, fdf->win, fdf->x_rot * fdf->scale + 200, fdf->y_rot * fdf->scale + 100, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	drawstuff2(t_mlx *fdf)
{
	int		x;
	int		y;
	int		z;
	int		i;

	fdf->data = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->size_line, &fdf->endian);
	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			z = fdf->map[y][x];
			i = y * fdf->size_line / fdf->bpp + x;
			setxy(fdf, x, y);
			if (x + 1 < fdf->cols)
				setxyn(fdf, x + 1, y);
			if (y + 1 < fdf->rows)
				setxyn(fdf, x, y + 1);
			x++;
		}
		y++;
	}
}

int	main(int ac, char *av[])
{
	t_mlx	*fdf;

	fdf = NULL;
	if (ac == 2)
	{
		fdf = initmlx(fdf, av[1]);
		intinput(av[1], fdf);
	}
	else
		return (0);
	mlx_put_image_to_window (fdf->ptr, fdf->win, fdf->img, 0, 0);
	fdfvalues(fdf);
//	drawstuff(fdf);
	drawstuff2(fdf);
	mlx_key_hook(fdf->win, keyinput, fdf);
	mlx_loop(fdf->ptr);
	return (0);
}
