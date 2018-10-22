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

t_vector new_vect(int x, int y, int z, int *color)
{
	t_vector vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;

	if (color == NULL)
		vect.color = 0xffffff;
	else
		vect.color = *color;
	return(vect);
}