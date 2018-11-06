/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:21:24 by sharris           #+#    #+#             */
/*   Updated: 2018/11/03 20:21:25 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define ROT_MIN(vx, vy, map) cos(map) * vx - sin(map) * vy
#define ROT_PLUS(vx, vy, map) cos(map) * vx + sin(map) * vy

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


/* Works
	if (color)
		vect.color = *color;
	else if (z <= 0)
	{
		if (z == 0)
			z = .1;
		vect.color = 0xff;
	}
	else if (z <= 1)
	{
		z = 0.0001;
		vect.color = 0xc2b280;
	}
	else if (z < 10)
		vect.color = gradient(0xc2b280, 0xffebcd, z/10);
	else 
		vect.color = 0xffffff;
*/

/*
** new_vect
** Initializes a new t_vector and scales values accordingly.
*/

int rainbow_gradient(int i)
{
	int color;

	if (i < 25)
		color = gradient(0xff0000, 0xffff00, (float)i * 4 / 100);
	else if ( i < 25 * 2)
		color = gradient(0xffff00, 0x00ff00, (float)(i - 25) * 4 / 100);
	else if ( i < 25 * 3)
		color = gradient(0x00ff00, 0x00ffff, (float)(i - 25 * 2) * 4 / 100);
	else if ( i < 25 * 4)
		color = gradient(0x00ffff, 0x0000ff, (float)(i - 25 * 3) * 4 / 100);
	else if ( i < 25 * 5)
		color = gradient(0x0000ff, 0xff00ff, (float)(i - 25 * 4) * 4 / 100);
	else
		color = 0xffffff;
	return(color);		
}

t_vector new_vect(double x, double y, double z, int *color)
{
	t_vector vect;

	if (color)
		vect.color = *color;
	else if (USE_RAINBOW)
		vect.color = rainbow_gradient((z - RAINBOW_MIN) * RAINBOW_SPREAD);
	else
		vect.color = 0x88ffff;
	vect.x = x;
	vect.y = y;
	vect.z = z;
	vect.wall = 0;
	return(vect);
}

/*
** new_wall_vect
** used to signify a teminated for t_vect arrays.
*/

t_vector new_wall_vect(void)
{
	t_vector vect;

	vect = new_vect(0, 0, 0, NULL);
	vect.wall = 1;
	return (vect);
}

t_vector rotate_vect(t_map map, t_vector v1)
{
	t_vector v = v1;
	// v = new_vect(cos(map.rxy) * v.x - sin(map.rxy) * v.y, (cos(map.rxy) * v.y + sin(map.rxy) * v.x), v.z, &v.color);
	// v = new_vect(cos(RXZ) * v.x - sin(RXZ) * v.z, v.y, cos(RXZ) * v.x + sin(RXZ) * v.z, &v.color);
	// v = new_vect(v.x, cos(RYZ) * v.y - sin(RYZ) * v.z, cos(RYZ) * v.z + sin(RYZ) * v.y, &v.color);
	v = new_vect(ROT_MIN(v.x, v.y, map.rxy), ROT_PLUS(v.y, v.x, map.rxy), v.z,
		&v.color);
	v = new_vect(ROT_MIN(v.x, v.z, map.rxz), v.y, ROT_PLUS(v.z, v.x, map.rxz),
		&v.color);
	v = new_vect(v.x, ROT_MIN(v.y, v.z, map.ryz), ROT_PLUS(v.z, v.y, map.ryz),
		&v.color);
	return(new_vect(v.x, v.y, v.z, &v.color));
}

t_vector setpos(t_vector v, t_map map)
{
	v = rotate_vect(map, v);
	v.px = (v.x * map.scale) + map.xo;
	v.py = (v.y * map.scale) + map.yo;
	// printf("%f x | %f y | %f z | %d pox | %d posy |\n", v.x, v.y, v.z, v.px, v.py);
	return (v);
}
