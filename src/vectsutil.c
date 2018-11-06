/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectsutil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 03:53:26 by sharris           #+#    #+#             */
/*   Updated: 2018/11/05 03:53:26 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	vect_iter(t_map *map, void (*f)(t_vector *))
{
	int i;
	int j;

	i = 0;
	while (map->vects[i] && map->vects[i][0].wall != 1)
	{
		j = 0;
		while (map->vects[i][j].wall != 1)
		{
			f(&(map->vects[i][j]));
			j++;
		}
		i++;
	}
}

void panev_up(t_vector *v)
{
	v->y -= PANE_SPD;
}

void panev_down(t_vector *v)
{
	v->y += PANE_SPD;
}

void panev_left(t_vector *v)
{
	v->x -= PANE_SPD;
}

void panev_right(t_vector *v)
{
	v->x += PANE_SPD;
}

