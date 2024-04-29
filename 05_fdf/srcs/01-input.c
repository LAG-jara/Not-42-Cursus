/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:58:27 by cwan              #+#    #+#             */
/*   Updated: 2024/04/29 14:44:32 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int 	x;
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

int	**intinput(char *av, t_mlx *fdf, int **arr)
{
	int	fd;
	int	i;
	int	j;
	char	*line;
	char	**splitline;

	i = 0;
	fdf->cols = numcol(av);
	fdf->rows = numrow(av);
	fd = open(av, O_RDONLY);
	arr = malloc(sizeof(int *) * (fdf->rows + 1));
	while (i < fdf->rows)
	{
		j = 0;
		line = get_next_line(fd);
		splitline = ft_split(line, ' ');
		arr[i] = malloc(sizeof(int) * (fdf->cols));
		while (splitline[j])
		{
			arr[i][j] = ft_atoi(splitline[j]);
			j++;
		}
		free(line);
		ft_free(splitline);
		i++;
	}
	arr[i] = NULL;
	close(fd);
	return (arr);
}
