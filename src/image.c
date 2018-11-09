/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:08:08 by sharris           #+#    #+#             */
/*   Updated: 2018/11/07 17:08:09 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define SCALE_PTS(x1, x2, i) ((x1) + (x2 - x1) * i)

/*
** write_color
** Assigns RGB to the image file given by mlx.
** Using addr[3] as a measure of distance to help handle hidden lines.
*/

void write_color(char *addr, int col, int z)
{
	if (addr)
	{
		if (addr[3] == '\0' || addr[3] < (char)z)
		{
			addr[3] = (char)z;
			addr[2] = col >> 16 & 0xff;
			addr[1] = col >> 8 & 0xff;
			addr[0] = col & 0xff;
		}
	}
}

void put_line_to_image(char *imgp, t_vector v1, t_vector v2)
{
	double hyp;
	double i;
	int j = 0;

	i = 0;
	if (!check_points_in_range(v1, v2))
		return ;
	// make_vect_in_range(&v1, &v2);
	hyp = sqrt(pow(v1.px - v2.px, 2) + pow(v1.py - v2.py, 2));
	while (i < 1)
	{
		if (SCALE_PTS(v1.px, v2.px, i) <= 0 || SCALE_PTS(v1.px, v2.px, i) > WIN_SIZE_X)
			i += 1 / hyp;
		else if (SCALE_PTS(v1.py, v2.py, i) <= 0 || SCALE_PTS(v1.py, v2.py, i) > WIN_SIZE_Y)
			i += 1 / hyp;
		else if ((j = lround(SCALE_PTS(v1.py, v2.py, i)) * 5120 + lround(SCALE_PTS(v1.px, v2.px, i)) * 4) < 3686400 && j > 0)
			write_color(&imgp[j], gradient(v1.color, v2.color, i), v1.z + v2.z);
		i += 1 / hyp;
	}
}

void draw_to_image(t_map *map, void *imgp)
{
	int i;
	int j;
	t_vector v1;
	t_vector v2;

	i = 0;
	while (map->vects[i])
	{
		j = 0;
		if (map->vects[i] && map->vects[i][j].wall != 1)
			v2 = setpos(map->vects[i][j], *map);
		while (map->vects[i][j].wall != 1)
		{
			v1 = v2;
			if (map->vects[i + 1])
				put_line_to_image(imgp, v1, setpos(map->vects[i + 1][j], *map));
			if (map->vects[i][j + 1].wall != 1)
				put_line_to_image(imgp, v1, (v2 = setpos(map->vects[i][j + 1], *map)));
			j++;
		}
		i++;
	}
}

void generate_image(t_map map)
{
	int bpp;
	int sizeline;
	int endian;
	char *dataaddr;
	int i = 0;

	dataaddr = mlx_get_data_addr(map.imgp, &bpp, &sizeline, &endian);
	ft_bzero(dataaddr, WIN_SIZE_X * WIN_SIZE_Y * 4);
	draw_to_image(&map, dataaddr);
	mlx_put_image_to_window(map.mlxp, map.winp, map.imgp, -1, 0);
	put_guide(&map);
}