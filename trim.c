/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:52:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/07 14:17:38 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*str_cut(char *str, int start, int end)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * end - start);
	while (start < end)
	{
		tmp[start] = str[start];
		start++;
	}
	//tmp[start] = '\0';
	return (tmp);
}

void	gen_new_token(t_info *info)
{
	char	**token;
	int		y;
	int		x;

	y = info->token.tok_y;
	/*ft_putnbr_fd(info->token.tok_y_b - y + 1, info->fd);
	ft_putchar_fd('\n', info->fd);*/
	token = (char **)malloc(sizeof(char *) * (info->token.tok_y_b - y) + 1);
	while (y < info->token.tok_y_b)
	{
		x = info->token.tok_x;
		token[y] = str_cut(info->token.map[y], x, info->token.tok_x_b + 1);
		ft_putendl_fd(token[y], info->fd);
		y++;
	}
	info->token.new_map = token;
}

void	trim_token(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->token.y)
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
		y++;
	}
	gen_new_token(info);
}
