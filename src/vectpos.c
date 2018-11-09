/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectpos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 02:10:34 by sharris           #+#    #+#             */
/*   Updated: 2018/11/09 02:10:34 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define B(vect) (vect->py - slope * vect->px)
#define INSIDE_WIN_X(vct) (vct.px > 0 && vct.px < WIN_SIZE_X)
#define INSIDE_WIN_Y(vct) (vct.py > 0 && vct.py < WIN_SIZE_Y)
#define IN_WIN_RANGE(vct) (INSIDE_WIN_X(vct) || INSIDE_WIN_Y(vct))

/*
** adjust_vect_pos
** if x coordinate is outside the window, sets x to 0 or WIN_SIZE_X and y
** to the appropriate intercept.
** Linewise with y.
*/

static void adjust_vect_pos(t_vector *v, double slope)
{
	if (v->px < 0)
	{
		v->py = (v->py + slope * v->px);
		v->px = 0;
	}
	else if (v->px > WIN_SIZE_X)
	{
		v->py = slope / WIN_SIZE_X - B(v);
		v->px = 0;
	}
	else if (v->py <= 0)
	{
		v->px = v->py + slope * v->px / slope;
		v->py = 0;
	}
	else if (v->py >= WIN_SIZE_Y)
	{
		v->px = (WIN_SIZE_Y - B(v)) / slope;
		v->py = WIN_SIZE_Y;
	}
}

/*
** If either vector lies inside the window / draws through the window
** return 1
** Otherwise returns 0
*/

int		check_points_in_range(t_vector v1, t_vector v2)
{
	if (IN_WIN_RANGE(v1) && IN_WIN_RANGE(v2))
		return (1);
	if (v1.py < 0 || v1.px < 0 || v2.px < 0 || v2.py < 0
	|| v1.px > WIN_SIZE_X || v1.py > WIN_SIZE_Y || v2.px > WIN_SIZE_X || v2.py > WIN_SIZE_Y)
		return (0) ;
	return(0);
}
