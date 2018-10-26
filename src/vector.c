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


// int beach_gradient(int z)
// {
// 	if (z < 0)
// 		return (0x0000ff);
// 	if (z == 1)
// 		return (0xc2b280);
// 	if (z < 10)
// 		return (gradient(0x228b22, 0x8b4513, z * 10));
// 	else
// 		return(gradient(0x8b4513, 0xffffff, (z-10) * 10));
// }

/*
	iso:
	vect.x = x * 1.8 * SCALE;
	vect.y = y * 1.4 * SCALE;
	vect.z = z * 1.5;
*/

t_vector new_vect(double x, double y, double z, int *color)
{
	t_vector vect;

	if (z == 0)
		z = 0.0001;
	vect.x = x * 1.8 * 1.4;
	vect.y = y * 1.5 * 1.4;
	vect.z = z * 1.5;
	vect.wall = 0;
	if (color == NULL)
		vect.color = 0xb7410e;
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