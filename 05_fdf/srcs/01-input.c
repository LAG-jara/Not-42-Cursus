/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:58:27 by cwan              #+#    #+#             */
/*   Updated: 2024/04/29 10:11:36 by cwan             ###   ########.fr       */
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

char	**initinput(char *av, char **map)
{
	int		fd;
	int		i;
	int		y;

	i = 0;
	y = numrow(av);

	map = malloc(sizeof(char *) * (y + 1));
	fd = open(av, O_RDONLY);
	while (i < y)
		map[i++] = get_next_line(fd);
	close(fd);
	map[i] = NULL;
	return (map);
}

int	**intinput(char *av, int **arr)
{
	int	fd;
	int	i;
	int	j;
	int	x;
	int y;
	char	*line;
	char	**splitline;

	i = 0;
	x = numcol(av);
	y = numrow(av);
	fd = open(av, O_RDONLY);
	arr = malloc(sizeof(int *) * (y + 1));
	while (i < y)
	{
		j = 0;
		line = get_next_line(fd);
		splitline = ft_split(line, ' ');
		arr[i] = malloc(sizeof(int) * (x + 1));
		while (splitline[j])
		{
			arr[i][j] = ft_atoi(splitline[j]);
			j++;
		}
		arr[i][j] = -999;
		free(line);
		ft_free(splitline);
		i++;
	}
	arr[i] = NULL;
	close(fd);
	return (arr);
}
