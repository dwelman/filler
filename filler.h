/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:25:33 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/07 15:01:23 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct	s_grid
{
	char	**map;
	char	**new_map;
	int		x;
	int		y;
	int		tok_x;
	int		tok_y;
	int		tok_x_b;
	int		tok_y_b;
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
	char	p2;
	t_valid	*link;
	int		link_c;
	t_valid	*pos;
	int		pos_c;
	int		turns;
	int		num_str;
	
	int		fd;//.......................................
}				t_info;

void			get_input(t_info *info);

int				**get_available_coords(t_info *info);

void			puttrace(char *file, char *str, int fd);

void			puttracen(char *file, char *str,  int num, int fd);

t_grid			new_grid(char **map, int x, int y);

t_valid			new_pos(int x, int y, int weight);

void			init_info(t_info *info);

int				place_token(t_info *info);

void			print_coord(t_valid coord, t_info *info);

void			cleanup(t_info *info);

void			get_player(t_info *info);

int				openfile(char *file);

void			trim_token(t_info *info);

#endif
