/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:03:54 by sharris           #+#    #+#             */
/*   Updated: 2018/11/07 16:03:56 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			scale_up(t_map *map)
{
	if (map->scale > .5)
	{
		map->scale *= 0.9;
		generate_image(*map);
	}
	return (0);
}

int			scale_down(t_map *map)
{
	if(map->scale < 450)
	{
		map->scale *= 1.1;
		generate_image(*map);
	}
	return (0);
}
