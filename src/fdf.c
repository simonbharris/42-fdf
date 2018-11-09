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

/*
** put_fdf
** Opens, intiializes, and obtains the vectors from the input file.
** prints the map, then initializes the key hooks and wait for user input.
*/

void	put_fdf(char *file)
{
	int		fd;
	t_map	*map;

	fd = ft_openfile(file);
	map = initmap();
	map->vects = get_vectors(fd, get_filelc(file, map) + 1, map);
	close(fd);
	init_map_window(map);
	map->imgp = mlx_new_image(map->mlxp, WIN_SIZE_X, WIN_SIZE_Y);
	(void)generate_image(*map);
	mlx_key_hook(map->winp, deal_key, map);
	mlx_hook(map->winp, 17, 1L << 17, close_fdf, NULL);
	mlx_loop(map->mlxp);
}
