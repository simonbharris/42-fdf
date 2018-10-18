/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 10:54:45 by sharris           #+#    #+#             */
/*   Updated: 2018/10/12 10:54:47 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftf.h>
#include <get_next_line.h>

#define TWIDTH 25

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

char **get_map(int fd)
{
	
}

void	put_fdf(char *file)
{
	void *mlxp;
	void *winp;
	int i = 0;
	char **map;

	// ? V -- Return the FD
	ft_openfile(file);
	map = get_map(ft_openfile(file));

//	! --- Get file conttents first, then deal with fdf.
	mlxp = mlx_init();
	winp = mlx_new_window(mlxp, WIN_SIZE_X, WIN_SIZE_Y, WIN_NAME);
	mlx_string_put(mlxp, winp, 25, 25, 0xfffff, "Hello World");
	while (i < 50)
	{
		mlx_pixel_put(mlxp, winp, 50 + i, 50 + i, 0xffffff);
		i++;
	}

	mlx_loop(mlxp);
}

/*
? -- Brainstorming
* Going to need to break the file up with ft_split.
* Afterwards, I need to be able to have a funciton that can pull  values one at a ttime
* -- The kicker is if I want to do the bonus, I need to grab and stored the color pattern in same block
* 
*A couple way that comes to mind with handling this, is to just parse down the line when printing.
* and to just write the lines as they go along.
* Another though tis to store them into structes; which come at the cost of more memory usages..
* Also with structes I can better keep track of other attributes
* -- But the need for other attributes is a question I do no yet have an answer to.

* As for printingthe map. I imagine I need to figure out the position of a point on the map
* this would be based off the relative x y cordinate in the file
* in addition to how the simulated plane is both rotated and tilted.
* -- there needs to be some tilt so that slopes can be seen.

* Currently, I don't know how to deal with simulating tilt. Rotations, Ithink, should be much more simply
* ... But I could be wrong.
* But once I discover where the position of each point of the file should be location.
* I simply have to draw lines from point A to adjustent points to B and C, and loop it
* through every point.

* At that point, is when I can use key hooks nad loops to respond to user input.
*/
