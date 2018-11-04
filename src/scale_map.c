#include <fdf.h>

int			scale_up(t_map *map)
{
	map->scale *= 0.9;
	printmap(map);
	return(0);
}

int			scale_down(t_map *map)
{
	map->scale *= 1.1;
	printmap(map);
	return(0);
}
