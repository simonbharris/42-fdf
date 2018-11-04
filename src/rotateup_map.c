#include <fdf.h>

int			incrementrxy(t_map *map)
{
	map->rxy += ROT_SPD;
	printmap(map);
	return(0);
}

int			incrementryz(t_map *map)
{
	map->ryz += ROT_SPD;
	printmap(map);
	return(0);
}

int			incrementrxz(t_map *map)
{
	map->rxz += ROT_SPD;
	printmap(map);
	return(0);
}
