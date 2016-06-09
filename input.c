/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:52:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/09 09:59:32 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_xy(t_grid *ret)
{
	char	*str;
	char	*line;

	get_next_line(0, &line);
	if (line != NULL)
	{
		str = ft_strchr(line, ' ');
		ret->y = ft_atoi(str++);
		str = ft_strchr(str, ' ');
		ret->x = ft_atoi(str);
		free(line);
	}
}

t_grid	get_token(t_info *info)
{
	char	*str;
	char	*line;
	t_grid	ret;
	int		i;

	get_xy(&ret);
	i = 0;
	ret.map = (char**)malloc(sizeof(char*) * ret.y);
	while (i < ret.y)
	{
		get_next_line(0, &line);
		if (line != NULL)
			ret.map[i] = line;
		i++;
	}
	ret.tok_x = ret.x;
	ret.tok_y = ret.y;
	ret.tok_x_b = 0;
	ret.tok_y_b = 0;
	return (ret);
}

t_grid	get_map(t_info *info)
{
	char	*line;
	char	*temp;
	char	*t2;
	t_grid	ret;
	int		i;

	get_xy(&ret);
	i = 0;
	ret.map = (char**)malloc(sizeof(char*) * ret.y);
	get_next_line(0, &line);
	while (i < ret.y)
	{
		get_next_line(0, &line);
		if (line != NULL)
		{
			t2 = line;
			line = ft_strchr(line, ' ');
			temp = ft_strdup(++line);
			free(t2);
			ret.map[i] = temp;
		}
		i++;
	}
	return (ret);
}

void	get_player(t_info *info)
{
	char	*str;
	char	*line;

	get_next_line(0, &line);
	str = ft_strchr(line, 'p');
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
	free(line);
}

void	get_input(t_info *info)
{
	info->board = get_map(info);
	info->token = get_token(info);
	trim_token(info);
}
