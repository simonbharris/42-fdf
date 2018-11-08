/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 10:54:45 by sharris           #+#    #+#             */
/*   Updated: 2018/10/20 15:38:20 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define SCALE_PTS(x1, x2, i) (x1) + (x2 - x1) * i

/*
** printmap
** Iterated through the map t_vect** 2D array and calls the line function
** between each valid point.
** Uses two t_vectors to store results of setpos for some optimizing.
*/

void			printmap(t_map *map)
{
	int			i;
	int			j;
	t_vector	v1;
	t_vector	v2;

	i = 0;
	mlx_clear_window(map->mlxp, map->winp);
	while (map->vects[i])
	{
		j = 0;
		if (map->vects[i] && map->vects[i][j].wall != 1)
			v2 = setpos(map->vects[i][j], *map);
		while (map->vects[i][j].wall != 1)
		{
			v1 = v2;
			if (map->vects[i + 1])
				putline(map, v1, setpos(map->vects[i + 1][j], *map));
			if (map->vects[i][j + 1].wall != 1)
				putline(map, v1, (v2 = setpos(map->vects[i][j + 1], *map)));
			j++;
		}
		i++;
	}
	put_guide(map);
}

/*
** putline
** A loop that draws a pixel line between two vectors.
** Does not draw lines whos points fall too far outside the window.
** The line draws a gradient of the two colors between v1 and v2.
*/

void			putline(t_map *map, t_vector v1, t_vector v2)
{
	double i;
	double hyp;

	i = 0;
	if (fmin(v1.px, v2.px) > WIN_SIZE_X || fmin(v1.py, v2.py) > WIN_SIZE_Y
	|| fmax(v1.px, v2.px) < 0 || fmax(v1.py, v2.py) < 0)
		return ;
	hyp = sqrt(pow(v1.px - v2.px, 2) + pow(v1.py - v2.py, 2));
	while (i < 1)
	{
		mlx_pixel_put(map->mlxp, map->winp,
			SCALE_PTS(v1.px, v2.px, i),
			SCALE_PTS(v1.py, v2.py, i),
			gradient(v1.color, v2.color, i));
		i += 1 / hyp;
	}
}

/*
** put_fdf
** Opens, intiializes, and obtains the vectors from the input file.
** prints the map, then initializes the key hooks and wait for user input.
*/

void			put_fdf(char *file)
{
	int		fd;
	t_map	*map;

	fd = ft_openfile(file);
	map = initmap();
	map->vects = get_vectors(fd, get_filelc(file, map) + 1, map);
	close(fd);
	init_map_window(map);
	printmap(map);
	mlx_key_hook(map->winp, deal_key, map);
	mlx_hook(map->winp, 17, 1L << 17, close_fdf, NULL);
	mlx_loop(map->mlxp);
}
