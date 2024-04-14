/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:58:27 by cwan              #+#    #+#             */
/*   Updated: 2024/04/14 18:28:28 by cwan             ###   ########.fr       */
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

char	**initinput(char *av)
{
	int		fd;	
	int		x;
	int		y;
	char	*line;
	char	**sub;

	fd = open(av, O_RDONLY);
	x = 0;
	y = 0;
	line = get_next_line(fd);
	sub = ft_split(line, ' ');
	free(line);
	while (sub[x])
		x++;
	ft_free(sub);
	ft_printf("%d, %d", x, y);
	return (NULL);
}
