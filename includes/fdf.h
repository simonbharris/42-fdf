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

# define WIN_SIZE_X 1280
# define WIN_SIZE_Y 720
# define WIN_MAX_SIZE (WIN_SIZE_X > WIN_SIZE_Y ? WIN_SIZE_X : WIN_SIZE_Y)
# define WIN_NAME "fdf"
# define DEFAULT_COLOR 0xffffff
# define X_OFF 400
# define Y_OFF 400
/*
** For the sake of arrays,
** x or y == -1 means the end of the array.
*/

typedef struct	s_vector
{
	double x;
	double y;
	double z;
	int px;
	int py;
	int wall;
	int color;
}				t_vector;

typedef struct	s_map
{
	void *mlxp;
	void *winp;
	double rx;
	double ry;
	double rz;
	double scale;
	int xo;
	int yo;
}				t_map;

int			ft_openfile(char *file);
void		put_fdf(char *file);
t_vector	**get_map(int fd);
void		mapdel(char ***map);
void putline(t_map *map, t_vector v1, t_vector v2);
t_vector new_vect(double x, double y, double z, int *color);
t_vector *splittovect(char **split, int ind);
t_map	*initmap(int *fd, char *file);
t_vector new_wall_vect(void);

int gradient(int v1, int v2, int pos);

#endif
