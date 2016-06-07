/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:52:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/07 17:16:27 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*str_cut(char *str, int start, int end)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * end - start);
	while (start < end)
	{
		tmp[i] = str[start];
		start++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	gen_new_token(t_info *info)
{
	char	**token;
	int		y;
	int		x;

	y = info->token.tok_y;
	token = (char **)malloc(sizeof(char *) * (info->token.tok_y_b - y));
	while (y < info->token.tok_y_b + 1)
	{
		x = info->token.tok_x;
		token[y] = str_cut(info->token.map[y], x, info->token.tok_x_b + 1);
		ft_putendl_fd(token[y], info->fd);
		y++;
	}
	info->token.map = token;
	info->token.x = info->token.tok_x_b - info->token.tok_x + 1;
	info->token.y = info->token.tok_y_b - info->token.tok_y + 1;
}

void	trim_token(t_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < info->token.y)
	{
		x = 0;
		while (x < info->token.x)
		{
			if (info->token.map[y][x] == '*')
			{
				if (x < info->token.tok_x)
					info->token.tok_x = x;
				if (y < info->token.tok_y)
					info->token.tok_y = y;
				if (x > info->token.tok_x_b)
					info->token.tok_x_b = x;
				if (y > info->token.tok_y_b)
					info->token.tok_y_b = y;
			}
			x++;
		}
	}
	if (info->token.tok_x || info->token.tok_y)
		gen_new_token(info);
}
