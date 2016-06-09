/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rough_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 06:22:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/09 08:41:15 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_diag(int *alive, t_info *info, int x, int y)
{
	if (y + 1 < info->board.y && x + 1 < info->board.x)
	{
		*alive += (ft_toupper(info->board.map[y + 1][x + 1] != '.'));
	}
	else
		*alive += 1;
	if (y + 1 < info->board.y && x - 1 > 0)
	{
		alive += (ft_toupper(info->board.map[y + 1][x - 1] != '.'));
	}
	else
		*alive += 1;
	if (y - 1 > 0 && x + 1 < info->board.x)
	{
		alive += (ft_toupper(info->board.map[y - 1][x + 1] != '.'));
	}
	else
		*alive += 1;
	if (y - 1 > 0 && x - 1 > 0)
	{
		*alive += (ft_toupper(info->board.map[y - 1][x - 1] != '.'));
	}
	else
		*alive += 1;
}

void	check_nextto(int *alive, t_info *info, int x, int y)
{
	if (x - 1 > 0)
	{
		*alive += (ft_toupper(info->board.map[y][x - 1]) != '.');
	}
	else
		*alive += 1;
	if (x + 1 < info->board.x)
	{
		*alive += (ft_toupper(info->board.map[y][x + 1] != '.'));
	}
	else
		*alive += 1;
	if (y - 1 > 0)
	{
		*alive += (ft_toupper(info->board.map[y - 1][x] != '.'));
	}
	else
		alive += 1;
	if (y + 1 < info->board.y)
	{
		*alive += (ft_toupper(info->board.map[y + 1][x] != '.'));
	}
	else
		*alive += 1;
}

int		check_cell(t_info *info, int x, int y)
{
	int		alive;
	char	piece;

	alive = 0;
	piece = ft_toupper(info->player);
	if (ft_toupper(info->board.map[y][x]) == piece)
	{
		check_nextto(&alive, info, x, y);
		check_diag(&alive, info, x, y);
		return (alive < 8);
	}
	return (0);
}

int		count_valid(t_info *info)
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

void	get_available_coords(t_info *info)
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
				info->link_c++;
			}
			x++;
		}
		y++;
	}
}
