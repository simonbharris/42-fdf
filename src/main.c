/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 10:08:37 by sharris           #+#    #+#             */
/*   Updated: 2018/10/12 10:28:02 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

// ! -- DEBUG ONLY
#include <stdio.h>

static void	fdf_usage(void)
{
	ft_putendl("usage: fdf target_file");
}

// TODO: Debug main
int main(int ac, char **av)
{
	int j, i = 0;
	int fd;

	// fd = open(av[1], O_RDONLY);
	// map = get_map(fd);
	int p1[2] = { 0, 0 };
	int p2[2] = { 800, 800 };
	char *str = \
"0 0 0,0x000fff 0 0\n \
0 0 0 0 0\n \
0 0 1 1 1";
	char **split;

	// char **nl = ft_strsplit(str, '\n');
	// t_vector **vects;
	// vects = (t_vector **)malloc(sizeof(t_vector) * 100);

	// while (nl[i])
	// {
	// 	split = ft_strsplit(nl[i], ' ');
	// 	vects[i] = splittovect(split, i);
	// 	i++;
	// }
	// vects[i] = 0;
	// i = 0;
	put_fdf(av[1]);

	// while (map[i])
	// {
	// 	j = 0;
	// 	while(map[i][j].x != -1)
	// 		printf("%d ", map[i][j++].color);
	// 	printf("\n");
	// 	i++;
	// }
	// printf("\n%d -- pow\n", (int)get_hex_value("f"));
	sleep(10);

	// mapdel(map);
	// mapdel(&map);
	// void *mlxp = mlx_init();
	// void *winp = mlx_new_window(mlxp, 800, 800, "fdf");
	// putline(mlxp, winp, p1, p2);
	// sleep(10);
	// mlx_loop(mlxp);

	// while(map[i])
	// {
	// 	j = 0;
	// 	while(map[i][j])
	// 	{
	// 		printf("%s ", map[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	// close(fd);
	// sleep(10);
	return(0);
}

// ! ---- True main
// int		main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		fdf_usage();
// 	else if (argc == 2)
// 		put_fdf(argv[1]);
// 	return (0);
// }
