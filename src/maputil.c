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

t_map	*initmap(char *file)
{
	t_map *map;

	if (NULL == (map = (t_map *)malloc(sizeof(t_map))))
	{
		ft_putendl("Malloc failed initializing map struct (initmap)");
		exit(5);
	}
	map->rxy = -.6;
	map->ryz = .6;
	map->rxz = 0;
	map->scale = 10;
	map->xo = X_OFF;
	map->yo = Y_OFF;
	map->vects = NULL;
	return (map);
}

void	init_map_window(t_map *map)
{
	if (NULL == (map->mlxp = mlx_init()))
	{
		ft_putendl("Error; MLX Init returned NULL. Exiting.");
		free(map);
		exit(3);
	}
	map->winp = mlx_new_window(map->mlxp, WIN_SIZE_X, WIN_SIZE_Y, WIN_NAME);
}

void	put_guide(t_map *map)
{
	mlx_string_put(map->mlxp, map->winp, WIN_SIZE_X -120, 12, 0xffffff, "Rotate: WASD + QE");
	mlx_string_put(map->mlxp, map->winp, WIN_SIZE_X -120, 12 * 2, 0xffffff, "Pane: Arrow keys");
	mlx_string_put(map->mlxp, map->winp, WIN_SIZE_X -120, 12 * 3, 0xffffff, "Scale: '-' '+'");
	mlx_string_put(map->mlxp, map->winp, WIN_SIZE_X -120, 12 * 4, 0xffffff, "Close: ESC");
}
