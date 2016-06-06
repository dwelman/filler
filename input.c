/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:52:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/06 11:31:39 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_grid	get_token(void)
{
	char	*str;
	char	*line;
	t_grid	ret;
	int		i;

	get_next_line(0, &str);
	str = ft_strchr(str, ' ');
	ret.y = ft_atoi(str++);
	str = ft_strchr(str, ' ');
	ret.x = ft_atoi(str);
	i = 0;
	ret.map = (char**)malloc(sizeof(char*) * ret.y);
	while (i < ret.y)
	{
		get_next_line(0, &line);
		ret.map[i] = line;
		puttrace("trace.txt", ret.map[i]);
		i++;
	}
	return (ret);
}

t_grid	get_map(void)
{
	char	*str;
	char	*line;
	t_grid	ret;
	int		i;

	get_next_line(0, &str);
	str = ft_strchr(str, ' ');
	ret.y = ft_atoi(str++);
	str = ft_strchr(str, ' ');
	ret.x = ft_atoi(str);
	i = 0;
	ret.map = (char**)malloc(sizeof(char*) * ret.y);
	get_next_line(0, &line);
	puttrace("trace.txt", "first line read = ");
	puttrace("trace.txt", line);
	while (i <= ret.y)
	{
		get_next_line(0, &line);
		line = ft_strchr(line, ' ');
		ret.map[i] = ++line;
		puttrace("trace.txt", ret.map[i]);
		i++;
	}
	return (ret);
}

void	get_player(t_info *info)
{
	char	*str;

	get_next_line(0, &str);
	str = ft_strchr(str, 'p');
	info->pnum = ft_atoi(++str) == 1;
	if (info->pnum == 1)
		info->player = 'O';
	else
		info->player = 'X';
}

void	get_input(t_info *info)
{
	int		i;
	char	*str;

	i = 0;
	info->board = get_map();
	info->token = get_token();
	puttracen("trace.txt", "board x = ", info->board.x);
	puttracen("trace.txt", "board y = ", info->board.y);
	puttracen("trace.txt", "token x = ", info->token.x);
	puttracen("trace.txt", "token y = ", info->token.y);
}
