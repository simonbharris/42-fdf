/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 10:28:34 by sharris           #+#    #+#             */
/*   Updated: 2018/10/12 10:28:35 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	error_fdf_line_elements(void)
{
	ft_putendl("Error, Number of line elements in file \
are not consistent. Exiting...");
	exit(4);
}

void	error_fdf_type(void)
{
	ft_putendl("Error: file must be a .fdf type");
	exit(9);
}

void	error_fdf_fileopen(void)
{
	ft_putendl("Error opening file, Check file name and permissions.");
	exit(1);
}

void	error_fdf_read(void)
{
	ft_putendl("File could not be read.");
	exit(2);
}
