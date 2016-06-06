/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:32:43 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/06 11:35:59 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_grid(t_grid grid)
{
	int	y;

	y = 1;
	while (y < grid.y)
	{
	//	puttrace("trace.txt","map[y]");
	//	puttrace("trace.txt", grid.map[y]);
		if (grid.map[y] != NULL)
			free(grid.map[y]);
	//	puttracen("trace.txt", "freed #", y);
		y++;
	}
	free(grid.map);
}

void	cleanup(t_info *info)
{
	//free_grid(info->board);
	free_grid(info->token);
	if (info->link != NULL)
	{
		free(info->link);
		info->link = NULL;
	}
	if (info->pos != NULL)
	{
		free(info->pos);
		info->pos = NULL;
	}
}
