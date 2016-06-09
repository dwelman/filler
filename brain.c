/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 16:42:15 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/09 16:56:55 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

float	calc_dist(int x1, int y1, int x2, int y2)
{
	float dist;

	dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	return (dist);
}

float	ideal_dist(t_info *info)
{
	float	start_d;

	start_d = calc_dist(info->op_x, info->op_y, info->st_x, info->st_y);
	return (start_d / 2);
}

int		update_index(t_info *info, int i, int d, float *ref)
{
	*ref = d - info->ideal_dist;
	return (i);
}

int		closest_index(t_info *info)
{
	int		index;
	int		i;
	float	d;
	float	ref;

	index = 0;
	i = 0;
	ref = calc_dist(info->pos[i].x, info->pos[i].y, info->op_x, info->op_y)
		- info->ideal_dist;
	while (++i < info->pos_c)
	{
		d = calc_dist(info->pos[i].x, info->pos[i].y, info->op_x, info->op_y);
		if (info->turns % 3 == 0)
		{
			if (d - info->ideal_dist < ref)
				index = update_index(info, i, d, &ref);
		}
		else if (d - info->ideal_dist > ref)
			index = update_index(info, i, d, &ref);
	}
	return (index);
}
