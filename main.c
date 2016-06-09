/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:28:20 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/09 16:44:23 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_results(t_info *info, int found)
{
	int	chosen_one;

	if (found)
	{
		chosen_one = closest_index(info);
		print_coord(info->pos[chosen_one], info);
	}
	else
	{
		ft_putstr("0 0\n");
		return (0);
	}
	return (1);
}

void	set_opp_xy(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->board.y)
	{
		x = 0;
		while (x < info->board.x)
		{
			if (info->board.map[y][x] == info->p2)
			{
				info->op_x = x;
				info->op_y = y;
			}
			if (info->board.map[y][x] == info->player)
			{
				info->st_x = x;
				info->st_y = y;
			}
			x++;
		}
		y++;
	}
	info->ideal_dist = ideal_dist(info);
}

int		main(void)
{
	t_info	info;
	int		found;

	init_info(&info);
	get_player(&info);
	while (1)
	{
		if (info.turns % info.pnum == 0)
		{
			get_input(&info);
			get_available_coords(&info);
			found = place_token(&info);
			if (check_results(&info, found) == 0)
				return (0);
			if (info.turns == 0)
				set_opp_xy(&info);
			cleanup(&info);
		}
		info.turns++;
	}
	return (0);
}
