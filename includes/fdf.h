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
# include <get_next_line.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

/*
** Meta-data for window
*/

# define WIN_SIZE_X 1280
# define WIN_SIZE_Y 720
# define WIN_MAX_SIZE (WIN_SIZE_X > WIN_SIZE_Y ? WIN_SIZE_X : WIN_SIZE_Y)
# define WIN_NAME "fdf"

/*
** Map defaults
*/

#define ROT_SPD .1
#define PANE_SPD 10
# define X_OFF 200
# define Y_OFF 200
# define DEFAULT_COLOR 0xffffff

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
	double rxy;
	double ryz;
	double rxz;
	double scale;
	int xo;
	int yo;
	t_vector **vects;
}				t_map;

int				ft_openfile(char *file);
void			put_fdf(char *file);
t_vector		**get_map(int fd);
void			mapdel(char ***map);
void			putline(t_map *map, t_vector v1, t_vector v2);
t_vector		new_vect(double x, double y, double z, int *color);
t_map			*initmap(int *fd, char *file);
t_vector		new_wall_vect(void);
int				ft_openfile(char *file);
int				get_filelc(char *filename);
t_vector rotate_vect(t_map map, t_vector v1);
t_vector setpos(t_vector v, t_map map);
t_vector	**get_vectors(int fd, int maxlines, t_map map);
void	printmap(t_map *map);

/*
** Keyhook fucnts
*/
int				deal_key(int key, void *params);

int			pane_right(t_map *map);
int			pane_left(t_map *map);
int			pane_down(t_map *map);
int			pane_up(t_map *map);
int			decrementrxy(t_map *map);
int			decrementryz(t_map *map);
int			decrementrxz(t_map *map);
int			incrementrxy(t_map *map);
int			incrementryz(t_map *map);
int			incrementrxz(t_map *map);
int			scale_up(t_map *map);
int			scale_down(t_map *map);
int			close_fdf(void *params);


int				gradient(int start, int end, double perc);

#endif
