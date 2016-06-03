/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:25:33 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 17:03:58 by ddu-toit         ###   ########.fr       */
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
	int		player;
}				t_info;

void			get_input(t_info *info);
void			puttrace(char *file, char *str);
void			puttracen(char *file, char *str,  int num);

#endif
