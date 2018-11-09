/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatedown_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:02:13 by sharris           #+#    #+#             */
/*   Updated: 2018/11/07 16:02:14 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			decrementrxy(t_map *map)
{
	map->rxy -= ROT_SPD;
	generate_image(*map);
	return (0);
}

int			decrementryz(t_map *map)
{
	map->ryz -= ROT_SPD;
	generate_image(*map);
	return (0);
}

int			decrementrxz(t_map *map)
{
	map->rxz -= ROT_SPD;
	generate_image(*map);
	return (0);
}
