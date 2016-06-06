/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:28:20 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/06 14:55:42 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_info	info;
	char	*str;
	int		found;

	init_info(&info);
	get_player(&info);
	info.fd = openfile("trace.txt");
	while (1)
	{
		if (info.turns % info.pnum == 0)
		{
			get_input(&info);
			get_available_coords(&info);
			found = place_token(&info);
			if (found == 0)
				return (0);
			cleanup(&info);
		}
		info.turns++;
	}
	return (0);
}
