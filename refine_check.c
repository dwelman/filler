/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:42:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/06 15:45:28 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_links(t_info *info, int x, int y)
{
	int	x_org;
	int	t_x;
	int	t_y;
	int	links;

	x_org = x;
	t_y = 0;
	links = 0;
	while (t_y < info->token.y)
	{
		t_x = 0;
		x = x_org;
	//	puttracen("trace.txt", "t_x = ", t_x);
	//	puttracen("trace.txt", "t_y = ", t_y);
	//	puttracen("trace.txt", "x = ", x);
	//	puttracen("trace.txt", "y = ", y, info->fd);
		while (t_x < info->token.x)
		{
			if (info->token.map[t_y][t_x] == '*'
					&& ft_toupper(info->board.map[y][x]) == ft_toupper(info->player))
						links++;
			if  (ft_toupper(info->board.map[y][x] == info->p2
					&& info->token.map[t_y][t_x] == '*'))
					links += 2;
			t_x++;
			x++;
		}
		y++;
		t_y++;
	}
	//puttracen("trace.txt", "links = ", links, info->fd);
	return (links);
}

int		is_valid(t_info *info, int x, int y)
{
	int	t_x;
	int	t_y;

	t_y = 0;
	if (x + info->token.x > info->board.x || y + info->token.y > info->board.y)//size check
		return (0);
	if (count_links(info, x, y) != 1)
		return (0);
	return (1);
}

int	place_token(t_info *info)
{
	int	i;
	int	x;
	int	y;
	int	tx;
	int	ty = 0;

	i = 0;
	info->pos_c = 0;
	info->pos = (t_valid*)malloc(sizeof(t_valid) * info->link_c * info->token.y * info->token.x);
	while (i < info->link_c) //loop through links found
	{
		y = info->link[i].y - info->token.y + 1;
		ty = 0;
		while (ty < info->token.y)
		{
			tx = 0;
			x = info->link[i].x - info->token.x + 1;
			while (tx < info->token.x)
			{
				if (x >= 0 && y >= 0)
					if (is_valid(info, x, y))
					{
						info->pos[info->pos_c] = new_pos(x, y, 0);
						//puttracen("trace.txt", "valid x = ", info->pos[info->pos_c].x, info->fd);
						//puttracen("trace.txt", "valid y = ", info->pos[info->pos_c].y, info->fd);
						info->pos_c++;
					}
				x++;
				tx++;
			}
			ty++;
			y++;
		}
		i++;
	}
	if (info->pos_c)
	{
		print_coord(info->pos[0]);
		return (1);
	}
	else
	{
		puttrace("trace.txt", "no valid found", info->fd);
		ft_putstr("0 0\n");
		return (0);
	}
}
