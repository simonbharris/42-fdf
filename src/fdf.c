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

t_vector	**get_map(int fd)
{
	t_vector	**map;
	char		*line;
	int			i;

	i = 0;
	map = (t_vector **)ft_memalloc(sizeof(t_vector *) * MAXMAP);
	while (i < MAXMAP && get_next_line(fd, &line))
	{
		map[i] = splittovect(ft_strsplit(line, ' '), i);
		free(line);
		i++;
	}
	map[i] = NULL;
	return(map);
}

// void	printmap(char ***map)
// {
// 	int i = 0;
// 	int j = 0;


// 	while (map[i])
// 	{
// 		while (map[i][j])
// 		{
// 			if (map[i + 1][j])
				
// 		}
// 	}
// }

void putline(void *mlxp, void *winp, int pos1[2], int pos2[2])
{
	double i;

	i = 0;
	while (i < 1)
	{
		mlx_pixel_put(mlxp, winp, pos1[0] + pos2[0] * i,
			pos1[1] + pos2[1] * i, DEFAULT_COLOR);
		i += 1 / (double)WIN_MAX_SIZE;
	}
}

void	put_fdf(char *file)
{

	int i;
	int fd;
	void *mlxp;
	void *winp;
	
	mlxp = mlx_init();
	winp = mlx_new_window(mlxp, WIN_SIZE_X, WIN_SIZE_Y, WIN_NAME);

	i = 0;
	// map = get_map(fd = ft_openfile(file));

	int p1[2] = { 0, 400 };
	int p2[2] = { 800, 0 };
	//	! --- Get file conttents first, then deal with fdf.

	// mlx_string_put(mlxp, winp, 25, 25, 0xfffff, "Hello World");
	// putline(mlxp, winp, p1, p2);
	// mlx_loop(mlxp);
}
