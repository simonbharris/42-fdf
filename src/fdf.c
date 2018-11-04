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
#include <get_next_line.h>

//! REMOVE 
#include <stdio.h>

#define TWIDTH 20

#define POSX(x,z) (x / z)
#define POSY(y,z) (y / z)
#define SCALE_PTS(x1, x2, i) (x1) + (x2 - x1) * i
#define Z(x) ((x).z == 0 ? 0.01 : (x).z)

/*
** printmap
** Iterated through the map t_vect** 2D array and calls the line function
** between each valid point.
*/

void	printmap(t_map *map)
{
	int i = 0;
	int j = 0;

	while (map->vects[i])
	{
		j = 0;
		while (map->vects[i][j].wall != 1)
		{
			if (map->vects[i + 1])
				putline(map, map->vects[i][j], map->vects[i + 1][j]);
			if (map->vects[i][j + 1].wall != 1)
				putline(map, map->vects[i][j], map->vects[i][j+1]);
			j++;
		}
		i++;
	}
}

/*
** putline
** 
*/

void putline(t_map *map, t_vector v1, t_vector v2)
{
	double i;
	double hyp;

	
	i = 0;
	v1 = rotate_vect(*map, v1);
	v2 = rotate_vect(*map, v2);
	v1 = setpos(v1, *map);
	v2 = setpos(v2, *map);
	hyp = sqrt(pow(v1.px - v2.px, 2) + pow(v1.py - v2.py, 2));
	while (i < 1)
	{
		if (fmin(v1.px, v2.px) > WIN_SIZE_X || fmin(v1.py, v2.py) > WIN_SIZE_Y || fmax(v1.px, v2.px) < 0 || fmax(v1.py, v2.py) < 0)
			break ;
		mlx_pixel_put(map->mlxp, map->winp,
			SCALE_PTS(v1.px, v2.px, i),
			SCALE_PTS(v1.py, v2.py, i),
			gradient(v1.color, v2.color, i));

		i += 1 / hyp;
	}
}

void	put_fdf(char *file)
{
	int i;
	int fd;
	t_map *map;
	
	map = initmap(&fd, file);
	map->vects = get_vectors(fd = ft_openfile(file), get_filelc(file), *map);

	printmap(map);

	close(fd);
	mlx_key_hook(map->winp, deal_key, map);
	mlx_loop(map->mlxp);

}
