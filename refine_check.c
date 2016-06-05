/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:42:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/05 15:12:54 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_valid(t_info *info, int x, int y)
{
	int	t_x;
	int	t_y;
	int	links;

	t_x = 0;
	t_y = 0;
	links = 0;
	if (x + info->token.x > info->board.x || y + info->token.y > info->board.y)//size check
		return (0);
	while (t_y < info->token.y)
	{
		puttrace("trace.txt", "while y");
		t_x = 0;
		while (t_x < info->token.x)
		{
			if (info->token.map[t_y][t_x] == ft_toupper(info->player)
					&& info->board.map[y][x] == ft_toupper(info->player))
						links++;
			 puttracen("trace.txt", "links = ", links);
			if (links > 1)
				return (0);
			t_x++;
			x++;
		}
		y++;
		t_y++;
	}
	return (links == 1);
}

void	place_token(t_info *info)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	info->pos_c = 0;
	info->pos = (t_valid*)malloc(sizeof(t_valid) * info->link_c * info->token.y * info->token.x);
	// ^ allocates enough for all the possible placements of token per link
	while (i < info->link_c)
	{
		y = info->link[i].y - info->token.y + 1;
		x = info->link[i].x - info->token.x + 1;
		if (is_valid(info, x, y))
		{
			info->pos[info->pos_c++] = new_pos(x, y, 0);
			puttracen("trace.txt", "x = ", x);
			puttracen("trace.txt", "y = ", y);
		}
		i++;
	}
	print_coord(info->pos[0]);
}
