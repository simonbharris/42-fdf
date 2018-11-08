/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pane_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:02:24 by sharris           #+#    #+#             */
/*   Updated: 2018/11/07 16:02:26 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			pane_up(t_map *map)
{
	map->yo -= PANE_SPD;
	printmap(map);
	return (0);
}

int			pane_down(t_map *map)
{
	map->yo += PANE_SPD;
	printmap(map);
	return (0);
}

int			pane_left(t_map *map)
{
	map->xo -= PANE_SPD;
	printmap(map);
	return (0);
}

int			pane_right(t_map *map)
{
	map->xo += PANE_SPD;
	printmap(map);
	return (0);
}
