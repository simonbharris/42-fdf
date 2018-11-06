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

//! REMOVE 
#include <stdio.h>

#define SCALE_PTS(x1, x2, i) (x1) + (x2 - x1) * i

/*
** printmap
** Iterated through the map t_vect** 2D array and calls the line function
** between each valid point.
** Uses two t_vectors to store results of setpos for some optimizing.
*/

void	printmap(t_map *map)
{
	int i = 0;
	int j = 0;
	t_vector v1;
	t_vector v2;
	
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
				putline(map, v1, (v2 = setpos(map->vects[i][j+1], *map)));
			j++;
		}
		i++;
	}
	put_guide(map);
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
	if (fmin(v1.px, v2.px) > WIN_SIZE_X || fmin(v1.py, v2.py) > WIN_SIZE_Y || fmax(v1.px, v2.px) < 0 || fmax(v1.py, v2.py) < 0)
		return ;
	if (abs(v1.px) > WIN_SIZE_X * 2 || abs(v1.py) > WIN_SIZE_Y * 2) 
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


void	put_fdf(char *file)
{
	int i;
	int fd;
	t_map *map;
	
	fd = ft_openfile(file);
	map = initmap(&fd, file);
	map->vects = get_vectors(fd = ft_openfile(file), get_filelc(file, map) + 1, map);
	init_map_window(map);
	printmap(map);
	close(fd);
	mlx_key_hook(map->winp, deal_key, map);
	mlx_hook(map->winp, 17, 1L << 17, close_fdf, NULL);
	mlx_loop(map->mlxp);

}
