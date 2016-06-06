/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:25:33 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/06 10:15:39 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct	s_grid
{
	char	**map;
	int		x;
	int		y;
}				t_grid;

typedef struct	s_valid
{
	int	x;
	int	y;
	int	weight;
}				t_valid;

typedef struct	s_info
{
	t_grid	board;
	t_grid	token;
	char	player;
	int		pnum;
	t_valid	*link;
	int		link_c;
	t_valid	*pos;
	int		pos_c;
	int		turns;
}				t_info;

void			get_input(t_info *info);

int				**get_available_coords(t_info *info);

void			puttrace(char *file, char *str);

void			puttracen(char *file, char *str,  int num);

t_grid			new_grid(char **map, int x, int y);

t_valid			new_pos(int x, int y, int weight);

void			init_info(t_info *info);

void			place_token(t_info *info);

void			print_coord(t_valid coord);

#endif
