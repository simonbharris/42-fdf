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

# define ROT_SPD .2
# define PANE_SPD 50
# define X_OFF WIN_SIZE_X / 2
# define Y_OFF WIN_SIZE_Y / 2
# define DEFAULT_COLOR 0xffffff

/*
** Fun stuff
** Any original z value below RAINBOW_MIN will be red.
** RAINBOW_SPREAD The lower the value, the greater the color range.
** Aim to set this so that all values in file multiplied by this value will
** 		have a difference no greater than 100 from min and max resulting values.
**		NOTE: ZSCALE (below) Will affect the perceived color range.
** Results below the minimum will be red, above the max is white.
** NOTE: color specified in a file always overrides these colors.
*/

# define USE_RAINBOW 1
# define RAINBOW_MIN 0
# define RAINBOW_SPREAD 20

/*
** ZSCALE affects the perceived depth, value scales with the magnitude of depth.
*/

# define ZSCALE .5

/*
** s_vector
** xyz -- Positions of the 3d vector.
** px, py -- Screen position.
** wall -- Used to null-terminate arrays.
** color -- Color of the vector point.
*/

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
	int		px;
	int		py;
	int		wall;
	int		color;
}				t_vector;

/*
** s_map
** mlxp, winp -- MLX pointers for the rendered map.
** r[xy|yz|xz] -- rotation values.
** scale -- scale of hte map, higher values == larger rendered map.
** xo | yo -- x and y origin, used as a point to print the map from.
** xmid | ymid -- Stores the middle of vector arrays for rotation purposes.
*/

typedef struct	s_map
{
	void		*mlxp;
	void		*winp;
	void		*imgp;
	float		rxy;
	float		ryz;
	float		rxz;
	float		scale;
	int			xo;
	int			yo;
	int			xmid;
	int			ymid;
	t_vector	**vects;
}				t_map;

void			put_fdf(char *file);
void			init_map_window(t_map *map);
void			put_guide(t_map *map);

int				ft_openfile(char *file);
int				get_filelc(char *filename, t_map *map);
t_map			*initmap(void);

t_vector		**get_vectors(int fd, int maxlines, t_map *map);
t_vector		new_vect(double x, double y, double z, int *color);
t_vector		new_wall_vect(void);
t_vector		rotate_vect(t_map map, t_vector v1);
t_vector		setpos(t_vector v, t_map map);
int				check_points_in_range(t_vector v1, t_vector v2);

void			generate_image(t_map map);

int				gradient(int start, int end, double perc);
int				rainbow_gradient(int i);

/*
** Keyhook fucnts
*/

int				deal_key(int key, void *params);

int				pane_right(t_map *map);
int				pane_left(t_map *map);
int				pane_down(t_map *map);
int				pane_up(t_map *map);
int				decrementrxy(t_map *map);
int				decrementryz(t_map *map);
int				decrementrxz(t_map *map);
int				incrementrxy(t_map *map);
int				incrementryz(t_map *map);
int				incrementrxz(t_map *map);
int				scale_up(t_map *map);
int				scale_down(t_map *map);
int				close_fdf(t_map *map);

/*
** Errors
** All error_fdf_* functions cause an exit.
*/

void			error_fdf_line_elements(void);
void			error_fdf_type(void);
void			error_fdf_fileopen(void);
void			error_fdf_read(void);

#endif
