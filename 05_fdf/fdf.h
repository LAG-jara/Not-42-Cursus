/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:22:37 by cwan              #+#    #+#             */
/*   Updated: 2024/05/06 14:33:26 by cwan             ###   ########.fr       */
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
	double	x_rot;
	double	y_rot;
	double	x_rotnext;
	double	y_rotnext;
	double	scale;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_mlx;

t_mlx	*initmlx(t_mlx *fdf, char *av);
int		intinput(char *av, t_mlx *fdf);

void	ft_freeint(int **arr);
void	ft_free(char **arr);

void	fdfvalues(t_mlx *fdf);
int		keyinput(int button, void *fdf);

#endif
