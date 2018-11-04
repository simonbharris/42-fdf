/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:59:09 by sharris           #+#    #+#             */
/*   Updated: 2018/11/03 20:59:10 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** get_light
** Obtain the proper brightness between two levels of brightness
** start and end must be between 0x00 and 0xFF.
** Perc picks the appropriate point between the two values.
*/

int get_light(int start, int end, double perc)
{
	return ((1 - perc) * start + perc * end);	
}

/*
** gradient
** Returns a color (0x000000 - 0xFFFFFF) between start and end, depending on
** the value of perc.
*/

int gradient(int start, int end, double perc)
{
	int r;
	int g;
	int b;

	if (start == end)
		return (start);
	r = get_light((start >> 16) & 0xFF, (end >> 16) & 0xFF, perc);
	g = get_light((start >> 8) & 0xFF, (end >> 8) & 0xFF, perc);
	b = get_light(start & 0xFF, end & 0xFF, perc);
	return (r << 16 | g << 8 | b);
}