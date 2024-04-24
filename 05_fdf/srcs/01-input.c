/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:58:27 by cwan              #+#    #+#             */
/*   Updated: 2024/04/24 12:02:31 by cwan             ###   ########.fr       */
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
/*
int	**numcol(char *line)
{
	int	i;
	int	j;
	int	**arr;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '-' && (line[i + 1] >= '0' && line[i + 1] <= '9')) \
		|| (line[i] >= '0' && line[i] <= '9'))
			j++;
		while (line[i - 1] != ' ' && line[i])
		i++;
	}
	arr = malloc(sizeof(int *) * (j + 1);
	arr[j] = '\0';
	j = 0;
	while (arr[j])
	{
		arr[j] = ft_atoi(ft_strchr(line, ' ');
	}
	return (arr);
}*/

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
