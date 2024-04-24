/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/04/24 12:04:13 by cwan             ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	char	**map;
	t_mlx	*fdf;

	fdf = NULL;
	map = NULL;
	if (ac == 2)
		map = initinput(av[1], map);
	for (int i = 0; map[i]; i++)
		ft_printf("%s", map[i]);
	fdf = initmlx(fdf, av[1]);
	ft_free(map);
	mlx_key_hook(fdf->win, keyinput, fdf);
	mlx_loop(fdf->ptr);
	return (0);
}
