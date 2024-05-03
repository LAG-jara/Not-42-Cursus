/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:43:13 by cwan              #+#    #+#             */
/*   Updated: 2024/05/03 12:09:56 by cwan             ###   ########.fr       */
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

float	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_freeint(int **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}
