/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:52:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/06 14:42:36 by ddu-toit         ###   ########.fr       */
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
		//puttrace("trace.txt", ret.map[i]);
		i++;
	}
	return (ret);
}

t_grid	get_map(void)
{
	char	*str;
	char	*line;
	char	*temp;
	char	*t2;
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
	while (i <= ret.y)
	{
		get_next_line(0, &line);
		t2 = line;
		line = ft_strchr(line, ' ');
		temp = ft_strdup(++line);
		free(t2);
		ret.map[i] = temp;
		//puttrace("trace.txt", ret.map[i]);
		i++;
	}
	return (ret);
}

void	get_player(t_info *info)
{
	char	*str;

	get_next_line(0, &str);
	str = ft_strchr(str, 'p');
	info->pnum = ft_atoi(++str);
	if (info->pnum == 1)
	{
		info->player = 'O';
		info->p2 = 'X';
	}
	else
	{
		info->player = 'X';
		info->p2 = 'O';
	}
}

void	get_input(t_info *info)
{
	int		i;
	char	*str;

	i = 0;
	info->board = get_map();
	info->token = get_token();
	//puttracen("trace.txt", "board x = ", info->board.x);
	//puttracen("trace.txt", "board y = ", info->board.y);
	//puttracen("trace.txt", "token x = ", info->token.x);
	//puttracen("trace.txt", "token y = ", info->token.y);
}
