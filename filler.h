/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:25:33 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 09:57:11 by daviwel          ###   ########.fr       */
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
}				t_info;

#endif
