/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:42:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/04 14:25:56 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(t_info *info, int x, int y)
{
	int	t_x;
	int	t_y;
	int	links;

	if (x + info->token.x > info->board.x || y + info->token.y > info->board.y)//size check
		return (0);
	while (y < info->token.y)
	{
		t_x = 0;
		while (x < info->token.x)
		{
			if (info->token.map[y][x] == info->player
					&& info->board.map[y][x] == info->player)
						links++;
			if (links > 1)
				return (0);
			x++;
		}
		y++;
	}
	//check for overlaps > 1 
	//check if token placement will fit on map
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
			info->pos[info->pos_c++] = new_pos(x, y, 0);
		i++;
	}
}
