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

/*
** new_vect
** Initializes a new t_vector and scales values accordingly.
*/

t_vector	new_vect(double x, double y, double z, int *color)
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
	return (vect);
}

/*
** new_wall_vect
** used to signify a teminated for t_vect arrays.
*/

t_vector	new_wall_vect(void)
{
	t_vector vect;

	vect = new_vect(0, 0, 0, NULL);
	vect.wall = 1;
	return (vect);
}

t_vector	rotate_vect(t_map map, t_vector v1)
{
	t_vector v;

	v = v1;
	v = new_vect(ROT_MIN(v.x, v.y, map.rxy), ROT_PLUS(v.y, v.x, map.rxy), v.z,
		&v.color);
	v = new_vect(ROT_MIN(v.x, v.z, map.rxz), v.y, ROT_PLUS(v.z, v.x, map.rxz),
		&v.color);
	v = new_vect(v.x, ROT_MIN(v.y, v.z, map.ryz), ROT_PLUS(v.z, v.y, map.ryz),
		&v.color);
	return (new_vect(v.x, v.y, v.z, &v.color));
}

t_vector	setpos(t_vector v, t_map map)
{
	v = rotate_vect(map, v);
	v.px = (v.x * map.scale) + map.xo;
	v.py = (v.y * map.scale) + map.yo;
	return (v);
}
