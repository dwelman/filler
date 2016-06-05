/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:42:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/05 15:54:29 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_valid(t_info *info, int x, int y)
{
	int	x_o;
	int	t_x;
	int	t_y;
	int	links;

	t_y = 0;
	links = 0;
	x_o = x;
	if (x + info->token.x > info->board.x || y + info->token.y > info->board.y)//size check
		return (0);
	while (t_y < info->token.y)
	{
		puttrace("trace.txt", "while y");
		t_x = 0;
		while (t_x < info->token.x)
		{
			puttrace("trace.txt", &info->token.map[t_y][t_x]);
			puttrace("trace.txt", &info->board.map[y][x]);
			if (ft_toupper(info->token.map[t_y][t_x]) == info->player
					&& ft_toupper(info->board.map[y][x]) == info->player)
						links++;
			 puttracen("trace.txt", "links = ", links);
			if (links > 1)
				return (0);
			t_x++;
			x++;
		}
		x -= t_x;
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
	int	tx = 0;
	int	ty = 0;

	i = 0;
	info->pos_c = 0;
	info->pos = (t_valid*)malloc(sizeof(t_valid) * info->link_c * info->token.y * info->token.x);
	// ^ allocates enough for all the possible placements of token per link
	while (i < info->link_c)
	{
		y = info->link[i].y - info->token.y + 1;
		x = info->link[i].x - info->token.x + 1;
		while (ty < info->token.y)
		{
			while (tx < info->token.x)
			{
				if (is_valid(info, x, y))
				{
					info->pos[info->pos_c++] = new_pos(x, y, 0);
					puttracen("trace.txt", "x = ", x);
					puttracen("trace.txt", "y = ", y);
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
