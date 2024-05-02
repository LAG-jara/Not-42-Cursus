/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:22:37 by cwan              #+#    #+#             */
/*   Updated: 2024/05/02 17:19:32 by cwan             ###   ########.fr       */
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
	int		cols;
	int		rows;
	double	theta;
	double	x_rot;
	double	y_rot;
	double	x_rotnext;
	double	y_rotnext;
	double	scale;
}			t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_img;

int		keyinput(int button, void *fdf);
t_mlx	*initmlx(t_mlx *fdf, char *av);
int		**intinput(char *av, t_mlx *fdf, int **arr);

float	ft_abs(int n);
void	ft_freeint(int **arr);
void	ft_free(char **arr);

#endif
