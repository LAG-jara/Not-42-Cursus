/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-mlxutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:21:11 by cwan              #+#    #+#             */
/*   Updated: 2024/05/06 14:26:01 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdfvalues(t_mlx *fdf)
{
	fdf->theta = 30 * M_PI / 180;
	if (fdf->rows < fdf->cols)
		fdf->scale = ((double)1000 / fdf->rows) / 2;
	else
		fdf->scale = ((double)1200 / fdf->cols) / 2;
}

int	keyinput(int button, void *fdf)
{
	t_mlx	*mlx;

	if (button == XK_Escape || button == 0)
	{
		mlx = (t_mlx *)fdf;
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		ft_freeint(mlx->map);
		free(mlx);
		exit(0);
	}
	return (0);
}
