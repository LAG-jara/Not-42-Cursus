/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:24:15 by cwan              #+#    #+#             */
/*   Updated: 2024/04/24 15:42:09 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyinput(int button, void *fdf)
{
	if (button == XK_Escape || button == 0)
	{
		mlx_destroy_image(((t_mlx*)fdf)->ptr, ((t_mlx*)fdf)->img);
		mlx_destroy_window(((t_mlx*)fdf)->ptr, ((t_mlx*)fdf)->win);
		free(((t_mlx*)fdf)->ptr);
		free(fdf);
		exit(0);
	}
	return (0);
}

t_mlx	*initmlx(t_mlx *fdf, char *av)
{
	char	*title;

	title = ft_strjoin("FdF: ", av);
	fdf = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	if (!fdf)
		return (ft_putstr_fd("Fdf malloc failed", 2), NULL);
	fdf->ptr = mlx_init();
	if (!fdf->ptr)
		return (ft_putstr_fd("Fdf mlx_init failed", 2), NULL);
	fdf->win = mlx_new_window(fdf->ptr, WIDTH, HEIGHT, title);
	free(title);
	if (!fdf->win)
		return (ft_putstr_fd("Fdf init window failed", 2), NULL);
	fdf->img = mlx_new_image(fdf->ptr, WIDTH, HEIGHT);
	if (!fdf->img)
		return (ft_putstr_fd("Fdf init image failed", 2), NULL);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->linesize,\
	 &fdf->endian);
	return(fdf);
}

void	drawstuff(t_mlx *fdf, int **map, char *av)
{
	int		x;
	int		y;
	double	x_rot;
	double	y_rot;
	double	theta;
	int		z;

	y = 0;
	theta = 30 * M_PI / 180;
	while (map[y])
	{
		x = 0;
		while (x < numcol(av))
		{
			z = map[y][x];
			x_rot = x * cos(theta) - y * sin(theta) * 0.7;
			y_rot = x * sin(theta) + y * cos(theta) * 0.7 - (z * 0.5);
			mlx_pixel_put(fdf->ptr, fdf->win, x_rot * 10 + 50, \
			y_rot * 10 + 50, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

float	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
/*
void drawstuff(t_mlx *fdf, int **map, char *av)
{
  int x;
  int y;
  double x_rot;
  double y_rot;
  double theta = 30.0 * M_PI / 180;
  double isometric_scale_x = 0.7;
  double isometric_scale_y = 0.7;
  double depth_scale = 0.5;

  int max_y = numrow(av); // Assuming a function to get number of rows
  int max_x = numcol(av); // Assuming a function to get number of columns

  y = 0;
  while (y < max_y - 1) { // Iterate until second-last row
    x = 0;
    while (x < max_x - 1) { // Iterate until second-last column
      int z = map[y][x]; // Current point's z-value

      // Calculate rotated coordinates for current point
      x_rot = (x * cos(theta) - y * sin(theta)) * isometric_scale_x;
      y_rot = (x * sin(theta) + y * cos(theta)) * isometric_scale_y - z * depth_scale;

      // Check for valid neighbors (adjust conditions based on your map dimensions)
      if (y + 1 < max_y) {
        // Calculate neighbor's rotated coordinates (downward neighbor)
        int neighbor_z = map[y + 1][x];
//        double neighbor_x_rot = (x * cos(theta) - (y + 1) * sin(theta)) * isometric_scale_x;
        double neighbor_y_rot = ((x * sin(theta) + (y + 1) * cos(theta)) * isometric_scale_y) - (neighbor_z * depth_scale);
        // Draw line using mlx_pixel_put (adjust loop for all neighbors)
        for (int i = 0; i <= ft_abs(y_rot - neighbor_y_rot); i++) { // Adjust loop based on line drawing approach
          double y_step = y_rot + ((neighbor_y_rot - y_rot) / ft_abs(y_rot - neighbor_y_rot)) * i;
          mlx_pixel_put(fdf->ptr, fdf->win, (x_rot * 10) + WIDTH / 2,
                        y_step + HEIGHT / 2, 0xFFFFFF);
        }
      }

      // Add similar logic to check and draw lines for right neighbor (x+1)

      x++;
    }
    y++;
  }
}*/

int	main(int ac, char *av[])
{
//	char	**map;
	int		**map;
	t_mlx	*fdf;

	fdf = NULL;
	map = NULL;
	fdf = initmlx(fdf, av[1]);
	if (ac == 2)
		map = intinput(av[1], map);
	drawstuff(fdf, map, av[1]);
//	ft_free(map);
	mlx_key_hook(fdf->win, keyinput, fdf);
	mlx_loop(fdf->ptr);
	return (0);
}
