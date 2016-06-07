/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 13:49:34 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/07 07:45:28 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coord(t_valid coord)
{
	ft_putnbr(coord.y);
	ft_putchar(' ');
	ft_putnbr(coord.x);
	ft_putchar('\n');
}

t_valid	new_pos(int x, int y, int weight)
{
	t_valid	new;

	new.x = x;
	new.y = y;
	new.weight = weight;
	return (new);
}

t_grid	new_grid(char **map, int x, int y)
{
	t_grid	new;

	new.map = map;
	new.x = x;
	new.y = y;
	return (new);
}

void	init_info(t_info *info)
{
	info->board = new_grid(NULL, 0, 0);
	info->token = new_grid(NULL, 0, 0);
	info->player = '.';
	info->link = NULL;
	info->link_c = 0;
	info->pos = NULL;
	info->pos_c = 0;
	info->turns = 0;
	info->num_str = 0;
}
