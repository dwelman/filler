/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:52:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/07 12:34:22 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_token(t_info *info)
{
	int	y;
	int	x;
	int	num;

	y = 0;
	num = 0;
	while (y < info->token.y)
	{
		x = 0;
		while (x < info->token.x)
		{
			if (info->token.map[y][x] == '*')
				info->num_str++;
			x++;
		}
		y++;
	}
}

t_grid	get_token(t_info *info)
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
//	puttrace("", "map :", info->fd);
	while (i < ret.y)
	{
		get_next_line(0, &line);
		ret.map[i] = line;
//		puttrace("", ret.map[i], info->fd);
		i++;
	}
	return (ret);
}

t_grid	get_map(t_info *info)
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
//	puttrace("", "map :", info->fd);
	get_next_line(0, &line);
	while (i < ret.y)
	{
		get_next_line(0, &line);
//		puttrace("", line, info->fd);
		t2 = line;
		line = ft_strchr(line, ' ');
		temp = ft_strdup(++line);
		free(t2);
		ret.map[i] = temp;
//		puttrace("", ret.map[i], info->fd);
		i++;
	}
	return (ret);
}

void	get_player(t_info *info)
{
	char	*str;

	get_next_line(0, &str);
	str = ft_strchr(str, 'p');
//	puttrace("", "player :", info->fd);
//	puttrace("", str - 1, info->fd);
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
	info->board = get_map(info);
	info->token = get_token(info);
	count_token(info);
}
