/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 12:13:47 by sharris           #+#    #+#             */
/*   Updated: 2018/10/12 12:13:50 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <math.h>
# include <fdf.h>
# include <fcntl.h>
# include <mlx.h>

# define WIN_SIZE_X 800
# define WIN_SIZE_Y 600
# define WIN_MAX_SIZE (WIN_SIZE_X > WIN_SIZE_Y ? WIN_SIZE_X : WIN_SIZE_Y)
# define WIN_NAME "fdf"
# define DEFAULT_COLOR 0xffffff
# define SCALE 25
# define X_OFF (WIN_SIZE_X / 2)
# define Y_OFF (WIN_SIZE_Y / 2)

/*
** For the sake of arrays,
** x or y == -1 means the end of the array.
*/

typedef struct	s_vector
{
	int x;
	int y;
	int z;
	int color;
}				t_vector;

typedef struct	s_map
{
	int rx;
	int ry;
	int rz;
	int scale;
	int xo;
	int yo;
}				t_map;

int			ft_openfile(char *file);
void		put_fdf(char *file);
t_vector	**get_map(int fd);
void		mapdel(char ***map);
void		putline(void *mlxp, void *winp, int pos1[2], int pos2[2]);
t_vector	new_vect(int x, int y, int z, int *color);
t_vector *splittovect(char **split, int ind);

#endif
