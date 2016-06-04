/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rough_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 06:22:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/04 12:40:22 by ddu-toit         ###   ########.fr       */
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
			if (ft_toupper(info->board.map[y][x - 1]) == piece)
				alive++;
		}
		else
			alive++;	
		if (x + 1 < info->board.x)
		{
			if (ft_toupper(info->board.map[y][x + 1] == piece))
				alive++;
		}
		else
			alive++;
		if (y - 1 > 0)
		{
			if (ft_toupper(info->board.map[y - 1][x] == piece))
				alive++;
		}
		else
			alive++;
		if (y + 1 < info->board.y)
		{
			if (ft_toupper(info->board.map[y + 1][x] == piece))
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
	int	i;

	y = 0;
	i = 0;
	info->pos = (t_valid*)malloc(sizeof(t_valid) * count_valid(info));
	while (y < info->board.y)
	{
		x = 0;
		while (x < info->board.x)
		{
			if (check_cell(info, x, y))
			{
				info->pos[i].x = x;
				info->pos[i].y = y;
				puttracen("trace.txt", "pos x = ", info->pos[i].x);
				puttracen("trace.txt", "pos y = ", info->pos[i].y);
				i++;
			}
			x++;
		}
		y++;
	}
	return (0);
}
