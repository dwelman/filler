/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:28:20 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/03 14:18:57 by ddu-toit         ###   ########.fr       */
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
	char	buffer[512];
	int	i;

//	i = 0;
	fd = open("trace.txt", O_WRONLY);
//	close(fd);
	get_next_line(0, &str);
	write(fd, str, strlen(str));
	close(fd);
	//i = read(0, str2, 10);
	//str2[i] = '\0';
	ft_putstr(str);
	/*ft_handlestr(&info);
	ft_putnbr(info.board.x);
	ft_putchar('\n');
	ft_putnbr(info.board.y);
	ft_putchar('\n');*/
	return (0);
}
