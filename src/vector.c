#include <fdf.h>

/*
**	typedef struct	s_vector
**	{
**		int x;
**		int y;
** 		int z;
**		int color;
**	}				t_vector;
*/

t_vector new_vect(double x, double y, double z, int *color)
{
	t_vector vect;

	vect.x = x * 2.5;
	vect.y = y * 2.5;
	vect.z = z;
	vect.wall = 0;
	if (color == NULL)
		vect.color = 0xff00ff;
	else
		vect.color = *color;
	return(vect);
}

t_vector new_wall_vect(void)
{
	t_vector vect;

	vect = new_vect(0, 0, 0, NULL);
	vect.wall = 1;
	return (vect);	
}