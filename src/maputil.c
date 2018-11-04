/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:19:54 by sharris           #+#    #+#             */
/*   Updated: 2018/10/20 16:20:00 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

void	mapdel(char ***map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			free(map[i][j]);
			map[i][j++] = NULL;
		}
		free(map[i]);
		map[i] = NULL;
		i++;
	}
}

t_map	*initmap(int *fd, char *file)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	map->mlxp = mlx_init();
	map->winp = mlx_new_window(map->mlxp, WIN_SIZE_X, WIN_SIZE_Y, WIN_NAME);
	map->rxy = 0;
	map->ryz = 0;
	map->rxz = 0;
	map->scale = 10;
	map->xo = X_OFF;
	map->yo = Y_OFF;
	map->vects = NULL;
	return (map);
}
