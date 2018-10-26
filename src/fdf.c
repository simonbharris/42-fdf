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
#define ZSCALE 2
#define MAXMAP 1000

#define SCALE(x) x * MAP_SCALE
#define POSX(x,z) (x / z)
#define POSY(y,z) (y / z)
#define SCALE_PTS(x1, x2, i) (x1) + (x2 - x1) * i
#define Z(x) ((x).z == 0 ? 0.01 : (x).z)
#define RXY(map) map.rx * map.ry
#define RYZ(map) map.ry * map.rz
#define RXZ(map) map.rx * map.rz
#define ROT_MIN(vx, vy, map) cos(map) * vx - sin(map) * vy
#define ROT_PLUS(vx, vy, map) cos(map) * vx + sin(map) * vy


int	ft_openfile(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("Error opening file.");
		exit(1);
	}
	if (read(fd, NULL, 0) < 0)
	{
		ft_putendl("File could not be read.");
		exit(2);
	}
	return (fd);
}

t_vector *splittovect(char **split, int ind)
{
	int i;
	int len;
	char *tmp;
	int col;
	t_vector *vects;

	i = 0;
	vects = (t_vector *)malloc(sizeof(t_vector)
		* (ft_parrlen((void **)split) + 1));
	while (split[i])
	{
		if ((tmp = ft_strchr(split[i], ',')))
			col = (int)ft_hextoi(tmp + 1);
		vects[i] = new_vect(i, ind, ft_atoi(split[i]), tmp == NULL ? NULL : &col);
		i++;
	}
	vects[i] = new_wall_vect();
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return(vects);
}

t_vector	**get_vectors(int fd)
{
	t_vector	**vects;
	char		*line;
	int			i;

	i = 0;
	vects = (t_vector **)ft_memalloc(sizeof(t_vector *) * MAXMAP);
	while (i < MAXMAP && get_next_line(fd, &line))
	{
		vects[i] = splittovect(ft_strsplit(line, ' '), i);
		free(line);
		i++;
	}
	vects[i] = NULL;
	return(vects);
}

void	printmap(t_map *map, t_vector **vects)
{
	int i = 0;
	int j = 0;

	while (1)
	{
		while (vects[i])
		{
			j = 0;
			while (vects[i][j].wall != 1)
			{
				if (vects[i + 1])
					putline(map, vects[i][j], vects[i + 1][j]);
				if (vects[i][j + 1].wall != 1)
					putline(map, vects[i][j], vects[i][j+1]);
				j++;
			}
			i++;
		}
		i = 0;
	}

}

int gradient(int v1, int v2, int pos)
{
	int col[2];
	int r[2];
	int g[2];
	int b[2];
	int i;
	
	if (pos == 0)
		pos = 1;
	col[0] = v1;
	col[1] = v2;
	i = 0;
	while (i < 2)
	{
		r[i] = col[i] & 0xff0000;
		g[i] = col[i] & 0x00ff00;
		b[i] = col[i] & 0x0000ff;
		i++;
	}
	return
	(
		((r[0] + abs(r[0] - r[1]) * pos / 100) & 0xff0000)
		| ((g[0] + abs(g[0] - g[1]) * pos / 100) & 0x00ff00)
		| ((b[0] + abs(b[0] - b[1]) * pos / 100) & 0x0000ff)
	);
}

t_vector rotate_vect(t_map map, t_vector v1)
{
	t_vector v = v1;
	// v = new_vect(cos(RXY) * v.x - sin(RXY) * v.y, (cos(RXY) * v.y + sin(RXY) * v.x), v.z, &v.color);
	// v = new_vect(cos(RXZ) * v.x - sin(RXZ) * v.z, v.y, cos(RXZ) * v.x + sin(RXZ) * v.z, &v.color);
	// v = new_vect(v.x, cos(RYZ) * v.y - sin(RYZ) * v.z, cos(RYZ) * v.z + sin(RYZ) * v.y, &v.color);
	v = new_vect(ROT_MIN(v.x, v.y, RXY(map)), ROT_PLUS(v.x, v.y, RXY(map)), v.z,
		&v.color);
	// v = new_vect(ROT_MIN(v.x, v.z, RXZ(map)), v.y, ROT_PLUS(v.x, v.z, RXZ(map)),
	// 	&v.color);
	v = new_vect(v.x, ROT_MIN(v.y, v.z, RYZ(map)), ROT_PLUS(v.y, v.z, RYZ(map)),
		&v.color);
	return(new_vect(v.x + 200, v.y + 10, v.z, &v.color));
}

t_vector setpos(t_vector v)
{
	v.px = v.x * 1;
	v.py = v.y * 1;
	return (v);
}

void putline(t_map *map, t_vector v1, t_vector v2)
{
	double i;
	double hyp;

	
	i = 0;
	v1 = rotate_vect(*map, v1);
	v2 = rotate_vect(*map, v2);
	v1 = setpos(v1);
	v2 = setpos(v2);
	hyp = sqrt(pow(v1.px - v2.px, 2) + pow(v1.py - v2.py, 2));
	while (i < 1)
	{
		if (fmin(v1.px, v2.px) > WIN_SIZE_X || fmin(v1.py, v2.py) > WIN_SIZE_Y || fmax(v1.px, v2.px) < 0 || fmax(v1.py, v2.py) < 0)
			break ;
		mlx_pixel_put(map->mlxp, map->winp,
			SCALE_PTS(v1.px, v2.px, i),
			SCALE_PTS(v1.py, v2.py, i),
			gradient(v2.color, v1.color, i * 100));

		i += 1 / hyp;
	}
}


void	put_fdf(char *file)
{

	int i;
	int fd;
	t_map *map;
	t_vector **vects;
	
	map = initmap(&fd, file);
	vects = get_vectors(fd = ft_openfile(file));

	printmap(map, vects);
	
	close(fd);
	mlx_loop(map->mlxp);
}
