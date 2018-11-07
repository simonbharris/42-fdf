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

/*
** get_strind (Get string index)
** Gets the index of a key code to use with a function array to
** link the proper function with the key.
*/

int		get_strind(char *str)
{
	int			i;
	const char	keyvals[14][6] = { { "65307"},
	{ "101" }, { "119" }, { "97" },
	{ "113" }, { "115" }, { "100" },
	{ "65362" }, { "65361" }, { "65364" }, { "65363" },
	{ "45" }, { "61" }, 0 };

	i = 0;
	while (keyvals[i][0])
	{
		if (ft_strequ(keyvals[i], str))
			return (i);
		i++;
	}
	return (-1);
}

/*
** initkeys
** Initializes the funciton pointer array
** to use as a dispatching table.
*/

void	initkeys(void *keys[13])
{
	keys[0] = &close_fdf;
	keys[1] = &incrementrxy;
	keys[2] = &incrementryz;
	keys[3] = &incrementrxz;
	keys[4] = &decrementrxy;
	keys[5] = &decrementryz;
	keys[6] = &decrementrxz;
	keys[7] = &pane_up;
	keys[8] = &pane_left;
	keys[9] = &pane_down;
	keys[10] = &pane_right;
	keys[11] = &scale_up;
	keys[12] = &scale_down;
}

/*
** deal_key
** Captures a key code and concerts it into the function
** pointer array for the proper function.
*/

int		deal_key(int key, void *params)
{
	int		ret;
	char	*skey;
	int		(*keyfuncts[13])(t_map *);

	initkeys((void **)&keyfuncts);
	if (NULL == (skey = ft_itoa(key)))
	{
		ft_putendl("Malloc failed (deal_key -> ft_itoa)");
		exit(7);
	}
	if ((ret = get_strind(skey)) != -1)
		keyfuncts[ret]((t_map *)params);
	free(skey);
	return (0);
}

/*
** close_fdf
** Closes fdf
*/

int		close_fdf(t_map *map)
{
	(void)map;
	exit(0);
	return (0);
}
