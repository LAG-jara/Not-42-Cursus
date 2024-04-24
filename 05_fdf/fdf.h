/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:22:37 by cwan              #+#    #+#             */
/*   Updated: 2024/04/24 12:03:13 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define WIDTH 1280
# define HEIGHT 720

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		linesize;
	int		endian;
}			t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	col;
}		t_point;


void	ft_free(char **arr);
char	**initinput(char *av, char **map);

#endif
