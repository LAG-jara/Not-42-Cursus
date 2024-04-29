/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:22:37 by cwan              #+#    #+#             */
/*   Updated: 2024/04/30 04:23:28 by cwan42           ###   ########.fr       */
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
# define WIDTH 800
# define HEIGHT 800

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	int		cols;
	int		rows;
}			t_mlx;

int		keyinput(int button, void *fdf);
t_mlx	*initmlx(t_mlx *fdf, char *av);
int		**intinput(char *av, t_mlx *fdf, int **arr);

float	ft_abs(int n);
void	ft_freeint(int **arr);
void	ft_free(char **arr);

#endif
