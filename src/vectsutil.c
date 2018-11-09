/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectsutil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 03:53:26 by sharris           #+#    #+#             */
/*   Updated: 2018/11/05 03:53:26 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	panev_up(t_vector *v)
{
	v->y -= PANE_SPD;
}

void	panev_down(t_vector *v)
{
	v->y += PANE_SPD;
}

void	panev_left(t_vector *v)
{
	v->x -= PANE_SPD;
}

void	panev_right(t_vector *v)
{
	v->x += PANE_SPD;
}
