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

static void	fdf_usage(void)
{
	ft_putendl("usage: fdf target_file");
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		fdf_usage();
	else if (argc == 2)
		put_fdf(argv[1]);
	return (0);
}
