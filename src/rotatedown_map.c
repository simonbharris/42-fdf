#include <fdf.h>

int			decrementrxy(t_map *map)
{
	map->rxy -= ROT_SPD;
	printmap(map);
	return(0);
}

int			decrementryz(t_map *map)
{
	map->ryz -= ROT_SPD;
	printmap(map);
	return(0);
}

int			decrementrxz(t_map *map)
{
	map->rxz -= ROT_SPD;
	printmap(map);
	return(0);
}