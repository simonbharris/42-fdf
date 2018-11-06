/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfuncts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:40:17 by sharris           #+#    #+#             */
/*   Updated: 2018/11/01 17:40:24 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		(*keyfuncts[])(t_map *) = { &close_fdf,
	&incrementrxy, &incrementryz, &incrementrxz,
	&decrementrxy, &decrementryz, &decrementrxz,
	&pane_up, &pane_left, &pane_down, &pane_right,
	&scale_up, &scale_down};
static char		keyvals[14][6] = { { "65307"},
	{ "101" }, { "119" }, { "97" },
	{ "113" }, { "115" }, { "100" },
	{ "65362" }, { "65361" }, { "65364" }, { "65363" },
	{ "45" }, { "61" }, 0 };

/*
** Keys:
** Close
** ESC = 65307
**
** Rotate					   >>   Rotated plane
** E = 101 | W = 119 | A =  97 >> + (XY | YZ | XZ)
** Q = 113 | S = 115 | D = 100 >> - (XY | YZ | XZ)
** Pane
** UP = 65362 | LEFT = 65362 | DOWN = 65362 | RIGHT = 65362
** '-' = 45 | '+' = 61 >> Scale Up/down
*/

int			get_strind(char *str)
{
	int i;
	
	i = 0;
	while(keyvals[i][0])
	{
		if (ft_strequ(keyvals[i], str))
			return (i);
		i++;
	}
	return (-1);
}

int			deal_key(int key, void *params)
{
	int ret;
	char *skey;

	if (NULL == (skey = ft_itoa(key)))
	{
		ft_putendl("Malloc failed (deal_key)");
		exit(7);
	}
	if ((ret = get_strind(skey)) != -1)
		keyfuncts[ret]((t_map *)params);
	free (skey);
    return(0);
}

int		close_fdf(t_map *map)
{
	(void)map;
	exit(0);
	return(0);
}