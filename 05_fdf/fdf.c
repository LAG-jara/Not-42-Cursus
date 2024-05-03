/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/05/03 10:53:42 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setxy(t_mlx *fdf, int x, int y);
void	setxyn(t_mlx *fdf, int x, int y);
void	drawstrline(t_mlx *fdf, int beginX, int beginY, int endX, int endY);

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
	drawstrline(fdf, fdf->x_rot * fdf->scale + 200, fdf->y_rot * fdf->scale + 100, fdf->x_rotnext * fdf->scale + 200, fdf->y_rotnext * fdf->scale + 100);
}

/*
t_img	*drawstuff(t_mlx *fdf, int **map)
{
	int		x;
	int		y;
	int		z;
	t_img	*img;
	int		*data;

	img = mlx_new_image(fdf->ptr, WIDTH, HEIGHT);
	if (!img)
		return (NULL);
	img->data = (int *)mlx_get_data_addr(img, &img->bpp, &img->len, &img->endian;
	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)

	}
	return (img);
}*/

void	fdfvalues(t_mlx *fdf)
{
	fdf->theta = 30 * M_PI / 180;
	if (fdf->rows < fdf->cols)
		fdf->scale = ((double)1000 / fdf->rows) / 2;
	else
		fdf->scale = ((double)1200 / fdf->cols) / 2;
}

int	main(int ac, char *av[])
{
	t_mlx	*fdf;

	fdf = NULL;
	if (ac == 2)
	{
		fdf = initmlx(fdf, av[1]);
		intinput(av[1], fdf);
//		img = mlx_new_image(fdf->ptr, WIDTH, HEIGHT);
	}
	else
		return (0);
//	mlx_put_image_to_window (fdf->ptr, fdf->win, img, 0, 0);
	fdfvalues(fdf);
	drawstuff(fdf);
	mlx_key_hook(fdf->win, keyinput, fdf);
	mlx_loop(fdf->ptr);
	return (0);
}
