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

#define TWIDTH 25
#define MAXMAP 1000
#define XO = 400;
#define YO = 400;
#define SCALE(x) x * MAP_SCALE
#define SCALE_PTS(x, y, i) ((double)(X_OFF + x * TWIDTH) + (y * TWIDTH) * i)
#define Z(x) ((x).z == 0 ? 1 : (x).z)

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
	vects[i] = new_vect(-1, -1, 0, NULL);
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

	while (vects[i])
	{
		j = 0;
		while (vects[i][j].x != -1)
		{
			// if (vects[i + 1] && vects[i + 1][j].x != -1)
			// 	putline(map, vects[i][j], vects[i + 1][j]);
			if (vects[i][j + 1].x != -1)
				putline(map, vects[i][j], vects[i][j+1]);
			j++;
		}
		i++;
	}
}

void putline(t_map *map, t_vector v1, t_vector v2)
{
	double i;

	i = 0;
	while (i < 1)
	{
		mlx_pixel_put(map->mlxp, map->winp, SCALE_PTS(v1.x, v2.x, i),
			SCALE_PTS(v1.y, v2.y, i), DEFAULT_COLOR);
		i += 1 / (double)WIN_MAX_SIZE;
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
