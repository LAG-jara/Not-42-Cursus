/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/04/19 15:42:37 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyinput(int button, void *fdf)
{
	if (button == XK_Escape || button == 0)
		return (mlx_destroy_window(fdfmlx_destroy_display(fdf), free(fdf), 0);
	return (0);
}
/*
void	*createwindow(void *mlx_ptr)
{
	void	*window;

	window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "WINDOW");
	if (!window)
		return (mlx_ptr);
	mlx_key_hook(window, keyinput, mlx_ptr);
//	mlx_hook(window, 17, 0L, keyinput, NULL);
	mlx_loop(mlx_ptr);
	return (window);
}*/

t_mlx	*initmlx(t_mlx *fdfptr, char *av)
{
	fdfptr = ft_calloc(1, sizeof(t_mlx));
	fdfptr->mlx_ptr = mlx_init();
	fdfptr->mlx_win = mlx_new_window(fdfptr, WIDTH, HEIGHT, "WINDOW")
}

int	main(int ac, char *av[])
{
	char	**map;
	t_mlx	*fdfptr;

	map = NULL;
	if (ac == 2)
	{
		map = initinput(av[1], map);
		for (int i = 0; map[i]; i++)
			ft_printf("%s", map[i]);
	}
	fdfptr = initmlx(fdfptr, av[1]);
	mlx_key_hook(window, keyinput, fdf);
	mlx_loop(fdf);
	ft_free(map);
	return (0);
}
