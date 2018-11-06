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

#define ROT_SPD .3
#define PANE_SPD 25
# define X_OFF WIN_SIZE_X / 2
# define Y_OFF WIN_SIZE_Y / 2
# define DEFAULT_COLOR 0xffffff

/*
** Fun stuff
** Any original z value below RAINBOWMIN will be red.
** RAINBOW_SPREAD The lower the value, the greater the color range.
** Aim to set this so that all values in file multiplied by this value will
** 		have a difference no greater than 100 from min and max resulting values.
**
** Results below the minimum will be red, above the max is white.
** Note, color specified in a file always overrides.
*/

#define USE_RAINBOW 1
#define RAINBOW_MIN 0
#define RAINBOW_SPREAD 2

/*
** ZSCALE affects the perceived depth, value scales with the magnitude of depth.
*/

# define ZSCALE .5
/*
** For the sake of arrays,
** x or y == -1 means the end of the array.
*/

typedef struct	s_vector
{
	float x;
	float y;
	float z;
	int px;
	int py;
	int wall;
	int color;
}				t_vector;

typedef struct	s_map
{
	void *mlxp;
	void *winp;
	float rxy;
	float ryz;
	float rxz;
	float scale;
	int xo;
	int yo;
	int xmid;
	int ymid;
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
int				get_filelc(char *filename, t_map *map);
t_vector rotate_vect(t_map map, t_vector v1);
t_vector setpos(t_vector v, t_map map);
t_vector	**get_vectors(int fd, int maxlines, t_map *map);
void	printmap(t_map *map);
void	init_map_window(t_map *map);
void	put_guide(t_map *map);

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
int		close_fdf(t_map *map);


int				gradient(int start, int end, double perc);

#endif
