/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:58:27 by cwan              #+#    #+#             */
/*   Updated: 2024/04/16 18:22:18 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
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

char	**initinput(char *av, char **map)
{
	int		fd;
	int		i;
	int		y;

	i = 0;
	y = numrow(av);

	map = malloc(sizeof(char *) * (y + 1));
	fd = open(av, O_RDONLY);
	while (i <= y)
		map[i++] = get_next_line(fd);
	close(fd);
	map[i] = NULL;
	return (map);
}
