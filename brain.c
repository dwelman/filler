#include "filler.h"
#include <stdio.h>//waefsrtgsrtsvrvbfsb

float	Qsqrt(float num)//erfsefgaeraev
{
	long	i;
	float	x2;
	float	y;
	float	th = 1.5F;

	th = 1.5F;
	x2 = num * 0.5F;
	y = num;
	i =  *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (th - (x2 * y * y));
	y = y * (th - (x2 * y * y));
	return (1 / y);
}

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
	return (start_d / 5);
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
		if (d - info->ideal_dist < ref)
		{
			index = i;
			ref = d - info->ideal_dist;
		}
		i++;
	}
	return (index);
}
