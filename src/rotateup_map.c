/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateup_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 00:53:43 by sharris           #+#    #+#             */
/*   Updated: 2018/11/06 00:53:44 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			incrementrxy(t_map *map)
{
	map->rxy += ROT_SPD;
	generate_image(*map);
	return (0);
}

int			incrementryz(t_map *map)
{
	map->ryz += ROT_SPD;
	generate_image(*map);
	return (0);
}

int			incrementrxz(t_map *map)
{
	map->rxz += ROT_SPD;
	generate_image(*map);
	return (0);
}
