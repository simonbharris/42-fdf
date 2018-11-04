/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:29:07 by sharris           #+#    #+#             */
/*   Updated: 2018/11/03 19:29:08 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** ft_openfile
** Opens a file and checks for basic errors.
** either exits the program with an error to stdout or returns a filedes (fd);
*/

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

int get_node_count(char *line)
{
	int n;

	n = 0;
	while (line && *line)
	{
		if (*line && !ft_iswhitespace(n))
			n++;
		line = ft_strchr(line, ' ') + 1;
	}
	return(n);
}

/*
** get_filelc (get file line count)
** Opens and reads through a file, returning the number of time that it read.
** as a line-count. Useful for knowing how much to malloc.
*/

int get_filelc(char *filename)
{
	char *line;
	int fd;
	int i;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		i++;
	}
	close(fd);
	return(i);
}

/*
** splittovect (ft_split output to *t_vectors)
** Takes a char** from an ft_split function and an index of the specified line to convert.
** Converts that "line" into an array of t_vectors and returns it.
** Frees up ft_split afterwards.
*/

static t_vector *splittovect(char **split, int ind, t_map map)
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
		vects[i] = new_vect(i, ind,
			ft_atoi(split[i]), tmp == NULL ? NULL : &col);
		i++;
	}
	vects[i] = new_wall_vect();
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return(vects);
}

/*
** get_vectors
** Returns a 2D array of vectors.
** a combination of the two indicies represents their position in the fdf grid.
*/

t_vector	**get_vectors(int fd, int maxlines, t_map map)
{
	t_vector	**vects;
	char		*line;
	int			i;

	i = 0;
	vects = (t_vector **)ft_memalloc(sizeof(t_vector *) * maxlines);
	while (i < maxlines && get_next_line(fd, &line))
	{
		vects[i] = splittovect(ft_strsplit(line, ' '), i, map);
		free(line);
		i++;
	}
	vects[i] = NULL;
	return(vects);
}
