/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/05/07 11:47:45 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline(t_mlx *fdf, int beginX, int beginY, int endX, int endY)
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
		int x = (int)pixelx;
		int y = (int)pixely;
	
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		{
			int index = (y *fdf->size_line) + (x * (fdf->bpp / 8));
			*(unsigned int *)(fdf->data + index) = 0x00FFFFFF;
		}
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
}

void	drawstuff(t_mlx *fdf)
{
	int		x;
	int		y;

	fdf->data = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->size_line, &fdf->endian);
	if (!fdf->data)
	{
		ft_putstr_fd("Fdf data addr failed\n", 2);
		return ;
	}
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
			x++;
		}
		y++;
	}
}

int	main(int ac, char *av[])
{
	t_mlx	*fdf;

	fdf = NULL;
	if (ac == 2 && !ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".fdf", 4))
	{
		fdf = initmlx(fdf, av[1]);
		if (!fdf)
			return (1);
		if (intinput(av[1], fdf) == -1)
			return (ft_freeint(fdf->map), free(fdf), 1);
	}
	else
		return (0);
	fdfvalues(fdf);

	drawstuff(fdf);
	mlx_put_image_to_window (fdf->ptr, fdf->win, fdf->img, 0, 0);
	mlx_key_hook(fdf->win, keyinput, fdf);
	mlx_loop(fdf->ptr);
	return (0);
}
