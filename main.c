/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:28:20 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/06 11:00:12 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_info	info;
	int		fd;
	char	*str;
	char	str2[100];
	char	buffer[512];

	init_info(&info);
	//fd = open("trace.txt", O_WRONLY);
	//write(fd, str, strlen(str));
	//if (info->turns == 0)
	get_player(&info);
	while (1)
	{
		if (info.turns % info.pnum == 0)
		{
			get_input(&info);
			get_available_coords(&info);
			place_token(&info);
		}
		info.turns++;
		cleanup(&info);
	}
	//close(fd);
	//ft_putstr(str);
	//ft_putstr("2 2");
	return (0);
}
