/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:52:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/03 17:12:10 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_grid	get_board(void)/*it fucking works*/
{
	char	*str;
	char	*line;
	char	**map;
	t_grid	ret;
	int		i;

	get_next_line(0, &str);
	str = ft_strchr(str, ' ');
	ret.y = ft_atoi(str++);
	str = ft_strchr(str, ' ');
	ret.x = ft_atoi(str);
	i = 0;
	map = (char**)malloc(sizeof(char*) * ret.y + 1);
	get_next_line(0, &line);
	while (i < ret.y + 1)
	{
		get_next_line(0, &line);
		line = ft_strchr(line, ' ');
		map[i] = ++line;
		puttrace("trace.txt", map[i]);
		i++;
	}
	return (ret);
}

void	get_player(t_info *info)
{
	char	*str;

	get_next_line(0, &str);
	str = ft_strchr(str, 'p');
	info->player = ft_atoi(++str);
	puttracen("trace.txt", "player = ", info->player);
}

void	get_input(t_info *info)
{
	int		i;
	char	*str;

	i = 0;
	get_player(info);
	//get_next_line(0, &str);
	info->board = get_board();
	//info->token = get_token()
	puttracen("trace.txt", "x = ", info->board.x);
	puttracen("trace.txt", "y = ", info->board.y);
}
