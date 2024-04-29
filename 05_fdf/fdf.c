/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/04/29 10:28:29 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyinput(int button, void *fdf)
{
	if (button == XK_Escape || button == 0)
	{
		mlx_destroy_image(((t_mlx*)fdf)->ptr, ((t_mlx*)fdf)->img);
		mlx_destroy_window(((t_mlx*)fdf)->ptr, ((t_mlx*)fdf)->win);
		free(((t_mlx*)fdf)->ptr);
		free(fdf);
		exit(0);
	}
	return (0);
}

t_mlx	*initmlx(t_mlx *fdf, char *av)
{
	char	*title;

	title = ft_strjoin("FdF: ", av);
	fdf = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	if (!fdf)
		return (ft_putstr_fd("Fdf malloc failed", 2), NULL);
	fdf->ptr = mlx_init();
	if (!fdf->ptr)
		return (ft_putstr_fd("Fdf mlx_init failed", 2), NULL);
	fdf->win = mlx_new_window(fdf->ptr, WIDTH, HEIGHT, title);
	free(title);
	if (!fdf->win)
		return (ft_putstr_fd("Fdf init window failed", 2), NULL);
	fdf->img = mlx_new_image(fdf->ptr, WIDTH, HEIGHT);
	if (!fdf->img)
		return (ft_putstr_fd("Fdf init image failed", 2), NULL);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->linesize,\
	 &fdf->endian);
	return(fdf);
}

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
		while (x < numwidth(map))
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

float	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	main(int ac, char *av[])
{
	int		**map;
	t_mlx	*fdf;

	fdf = NULL;
	map = NULL;
	if (ac == 2)
		map = intinput(av[1], map);
	fdf = initmlx(fdf, av[1]);
	drawstuff(fdf, map);
	ft_freeint(map);
	mlx_key_hook(fdf->win, keyinput, fdf);
	mlx_loop(fdf->ptr);
	return (0);
}
