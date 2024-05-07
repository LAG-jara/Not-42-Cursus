/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:22:37 by cwan              #+#    #+#             */
/*   Updated: 2024/05/07 12:18:53 by cwan             ###   ########.fr       */
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
//# include <stdlib.h>
//# include <stdio.h>
# define WIDTH 1200
# define HEIGHT 1000

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	int		**map;
	int		cols;
	int		rows;
	double	theta;
	double	xrot;
	double	yrot;
	double	xrotn;
	double	yrotn;
	double	scale;
	double	xd;
	double	yd;
	int		pixels;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_mlx;

//01-input.c
void	fdfvalues(t_mlx *fdf);
int		intinput(char *av, t_mlx *fdf);
t_mlx	*initmlx(t_mlx *fdf, char *av);

//02-mlxutils.c
int		keyinput(int button, void *fdf);
void    drawstuff(t_mlx *fdf);

//03-utils.c
void	ft_freeint(int **arr);
void	ft_free(char **arr);

#endif
