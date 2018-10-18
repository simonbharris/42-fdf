/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 12:13:47 by sharris           #+#    #+#             */
/*   Updated: 2018/10/12 12:13:50 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <math.h>
# include <fdf.h>
# include <fcntl.h>
# include <mlx.h>

# define WIN_SIZE_X 800
# define WIN_SIZE_Y 600
# define WIN_NAME "fdf"

int	ft_openfile(char *file);
void	put_fdf(char *file);

#endif
