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

#define ROT_SPD .1

int			close_fdf(t_map *map);
int			incrementrxy(t_map *map);
int			incrementryz(t_map *map);
int			incrementrxz(t_map *map);

static int		(*keyfuncts[])(t_map *) = { &close_fdf, &incrementrxy, &incrementryz, &incrementrxz };
static char		keyvals[5][6] = { { "65307"}, { "122" }, { "120" }, { "99" }, 0 };

int			close_fdf(t_map *map)
{
	free(map);
	exit(0);
}

int			incrementrxy(t_map *map)
{
	map->rxy += ROT_SPD;
	mlx_clear_window(map->mlxp, map->winp);
	printmap(map);
}

int			incrementryz(t_map *map)
{
	map->ryz += ROT_SPD;
	mlx_clear_window(map->mlxp, map->winp);
	printmap(map);
}

int			incrementrxz(t_map *map)
{
	map->rxz += ROT_SPD;
	mlx_clear_window(map->mlxp, map->winp);
	printmap(map);
}

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
	printf("Returning -1\n");
	return (-1);
}

int			deal_key(int key, void *params)
{
    // printf("Key No. Pressed: %d\n", key);
	int ret;
	char *skey;

	skey = ft_itoa(key);
	if ((ret = get_strind(skey)) != -1)
		keyfuncts[ret]((t_map *)params);
	free (skey);
    return(0);
}
