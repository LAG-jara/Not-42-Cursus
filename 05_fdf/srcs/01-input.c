/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:58:27 by cwan              #+#    #+#             */
/*   Updated: 2024/04/24 13:56:08 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **arr)
{
	int		i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

int	numrow(char *av)
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

int	numcol(char *av)
{
	int		fd;
	int 	x;
	char	**line;

	fd = open(av, O_RDONLY);
	x = 0;
	line = ft_split(get_next_line(fd), ' ');
	while (line[x])
		x++;
	ft_free(line);
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
	char	**line;

	i = 0;
	x = numcol(av);
	y = numrow(av);
	fd = open(av, O_RDONLY);
	arr = malloc(sizeof(int *) * (y + 1));
	while (i < y)
	{
		j = 0;
		line = ft_split(get_next_line(fd), ' ');
		arr[i] = malloc(sizeof(int) * (x + 1));
		while (line[j])
		{
			arr[i][j] = ft_atoi(line[j]);
			j++;
		}
//		arr[i][j] = '\0';
		ft_free(line);
		i++;
	}
	arr[i] = NULL;
	close(fd);
	return (arr);
}
