/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rough_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 06:22:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/07 08:12:09 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_cell(t_info *info, int x, int y)
{
	int		alive;
	char	piece;

	alive = 0;
	piece = ft_toupper(info->player);
	if (ft_toupper(info->board.map[y][x]) == piece)
	{
		if (x - 1 > 0)
		{
			if (ft_toupper(info->board.map[y][x - 1]) != '.')
				alive++;
		}
		else
			alive++;	
		if (x + 1 < info->board.x)
		{
			if (ft_toupper(info->board.map[y][x + 1] != '.'))
				alive++;
		}
		else
			alive++;
		if (y - 1 > 0)
		{
			if (ft_toupper(info->board.map[y - 1][x] != '.'))
				alive++;
		}
		else
			alive++;
		if (y + 1 < info->board.y)
		{
			if (ft_toupper(info->board.map[y + 1][x] != '.'))
				alive++;
		}
		else
			alive++;
		if (alive < 4)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	count_valid(t_info *info)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (y < info->board.y)
	{
		x = 0;
		while (x < info->board.x)
		{
			if (check_cell(info, x, y))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	**get_available_coords(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	info->link_c = 0;
	info->link = (t_valid*)malloc(sizeof(t_valid) * count_valid(info));
	while (y < info->board.y)
	{
		x = 0;
		while (x < info->board.x)
		{
			if (check_cell(info, x, y))
			{
				info->link[info->link_c] = new_pos(x, y, 0);
				//puttracen("trace.txt", "link x = ", info->link[info->link_c].x);
				//puttracen("trace.txt", "link y = ", info->link[info->link_c].y);
				info->link_c++;
			}
			x++;
		}
		y++;
	}
	return (0);
}
