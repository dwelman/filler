/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:42:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/06 10:27:51 by ddu-toit         ###   ########.fr       */
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
		//puttracen("trace.txt", "t_x = ", t_x);
		//puttracen("trace.txt", "t_y = ", t_y);
		//puttracen("trace.txt", "x = ", x);
		//puttracen("trace.txt", "y = ", y);
		while (t_x < info->token.x)
		{
			if (info->token.map[t_y][t_x] == '*'
					&& ft_toupper(info->board.map[y][x]) == ft_toupper(info->player))
						links++;
			if (links > 1)
				return (0);
			t_x++;
			x++;
		}
		y++;
		t_y++;
	}
	//puttracen("trace.txt", "links = ", links);
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

void	place_token(t_info *info)
{
	int	i;
	int	x;
	int	y;
	int	tx;
	int	ty = 0;

	i = 0;
	info->pos_c = 0;
	info->pos = (t_valid*)malloc(sizeof(t_valid) * info->link_c * info->token.y * info->token.x);
	// ^ allocates enough for all the possible placements of token per link
	while (i < info->link_c) //loop through links found
	{
		y = info->link[i].y - info->token.y + 1;
		x = info->link[i].x - info->token.x + 1;
		//puttracen("trace.txt", "testing x = ", x);
		//puttracen("trace.txt", "testing y = ", y);
		//loop through all poossible placements for link, testing validity
		while (ty < info->token.y)
		{
			tx = 0;
			x = info->link[i].x - info->token.x + 1;
			while (tx < info->token.x)
			{
				if (is_valid(info, x, y))
				{
					info->pos[info->pos_c++] = new_pos(x, y, 0);
					//puttracen("trace.txt", "valid x = ", x);
					//puttracen("trace.txt", "valid y = ", y);	
				}
				x++;
				tx++;
			}
			ty++;
			y++;
		}
		i++;
	}
	print_coord(info->pos[0]);
}
