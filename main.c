/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:28:20 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 10:57:25 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_handlestr(t_info *info)
{
	char	*temp;

	get_next_line(0, &temp);
	get_next_line(0, &temp);
	temp = ft_strchr(temp, ' ');
	info->board.x = ft_atoi(temp);
	temp = ft_strchr(temp, ' ');
	info->board.x = ft_atoi(temp);
}

int	main(void)
{
	//t_info	info;
	int		fd;
	char	*str;
	char	str2[100];
	int	i;

	i = 0;
	fd = open("data.txt", O_RDONLY);
	while (i < 5)
	{
		get_next_line(fd, &str);
		ft_putendl(str);
		i++;
	}
	read(0, str2, 80);
	ft_putstr(str2);
	/*ft_handlestr(&info);
	ft_putnbr(info.board.x);
	ft_putchar('\n');
	ft_putnbr(info.board.y);
	ft_putchar('\n');*/
	return (0);
}
