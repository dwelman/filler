/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:42:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/07 15:02:00 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_links(t_info *info, int x, int y)
{
	int	t_x;
	int	t_y;
	int	links;
	int	star;

	t_y = -1;
	links = 0;
	star = 0;
	while (++t_y < info->token.y && star < info->num_str)
	{
		t_x = 0;
		while (t_x < info->token.x && star < info->num_str && x < info->board.x && y < info->board.y)
		{
			star += (info->token.map[t_y][t_x] == '*');
			if (info->token.map[t_y][t_x] == '*'
					&& ft_toupper(info->board.map[y][x]) == info->player)
						links++;
			if  (ft_toupper(info->board.map[y][x] == info->p2
					&& info->token.map[t_y][t_x] == '*'))
						return (2);
			t_x++;
			x++;
		}
		x -= t_x;
		y++;
	}
	return (links);
}

int		is_valid(t_info *info, int x, int y)
{
	int	t_x;
	int	t_y;

	t_y = 0;
	if (x + info->token.x > info->board.x
			|| y + info->token.y - 1 > info->board.y)
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
	int	ty;

	i = 0;
	info->pos = (t_valid*)malloc(sizeof(t_valid) * info->link_c * info->token.y * info->token.x);
	while (i < info->link_c)
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
						info->pos[info->pos_c++] = new_pos(x, y, 0);
				x++;
				tx++;
			}
			ty++;
			y++;
		}
		i++;
	}
	if (info->pos_c > 0)
	{
		print_coord(info->pos[0], info);
		return (1);
	}
	else
	{
		i = 0;
		puttrace("","player  : ", info->fd);
		write(info->fd, &info->player, 1);
		puttracen("","link_c = ", info->link_c, info->fd);
		while (i < info->link_c)
		{
			puttracen("","link x = ", info->link[i].x, info->fd);
			puttracen("","link y = ", info->link[i].y, info->fd);
			i++;
		}
		puttrace("trace.txt", "no valid found", info->fd);
		ft_putstr("0 0\n");
		exit (0);
	}
}
