/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:25:33 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/04 07:42:35 by daviwel          ###   ########.fr       */
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

typedef struct	s_info
{
	t_grid	board;
	t_grid	token;
	char	player;
}				t_info;

void			get_input(t_info *info);

int				**get_available_coords(t_info *info);

void			puttrace(char *file, char *str);

void			puttracen(char *file, char *str,  int num);

#endif
