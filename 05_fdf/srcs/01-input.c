/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:58:27 by cwan              #+#    #+#             */
/*   Updated: 2024/05/06 09:14:34 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyinput(int button, void *fdf)
{
	if (button == XK_Escape || button == 0)
	{
		t_mlx	*mlx;

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
	return (fdf);
}

static int	numrow(char *av)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(av, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (y);
}

static int	numcol(char *av)
{
	int		fd;
	int		x;
	char	*line;
	char	**splitline;

	fd = open(av, O_RDONLY);
	x = 0;
	line = get_next_line(fd);
	splitline = ft_split(line, ' ');
	while (splitline[x])
		x++;
	free(line);
	ft_free(splitline);
	close(fd);
	return (x);
}

int	intinput(char *av, t_mlx *fdf)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**splitline;

	i = 0;
	fdf->cols = numcol(av);
	fdf->rows = numrow(av);
	fd = open(av, O_RDONLY);
	fdf->map = malloc(sizeof(int *) * (fdf->rows + 1));
	if (!fdf->map)
		return (close(fd), ft_putstr_fd("Fdf malloc failed", 2), 1);
	while (i < fdf->rows)
	{
		j = -1;
		line = get_next_line(fd);
		splitline = ft_split(line, ' ');
		fdf->map[i] = malloc(sizeof(int) * (fdf->cols));
		while (splitline[++j])
			fdf->map[i][j] = ft_atoi(splitline[j]);
		(void)(free(line), ft_free(splitline));
		i++;
	}
	fdf->map[i] = NULL;
	return (close(fd), 0);
}
