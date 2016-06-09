/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:28:20 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/09 11:40:46 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_results(t_info *info, int found)
{
	if (found)
	{
		//calc ideal dist
		//choose coord closest to ideal
		print_coord(info->pos[0], info);
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
				info->sx_y = y;
			}
			x++;
		}
		y++;
	}
	ideal_dist(map);
	ft_putstr_fd("op_x = ",info->fd);
	ft_putnbr_fd(info->op_x, info->fd);
	ft_putstr_fd("\nop_y = ", info->fd);
	ft_putnbr_fd(info->op_y, info->fd);
}

int	main(void)
{
	t_info	info;
	int		found;

	init_info(&info);
	get_player(&info);
	//get original x & y of opponent
	info.fd = openfile("trace.txt");
	while (1)
	{
		if (info.turns % info.pnum == 0)
		{
			get_input(&info);
			get_available_coords(&info);
			found = place_token(&info);
			if (check_results(&info, found) == 0)
				return (0);
			cleanup(&info);
		}
		if (info.turns == 0)
			set_opp_xy(&info);
		info.turns++;
	}
	close(info.fd);
	return (0);
}
