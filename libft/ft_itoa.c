/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:59:40 by daviwel           #+#    #+#             */
/*   Updated: 2016/05/20 12:59:43 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i += 1;
	while (n /= 10)
		i += 1;
	return (i + 1);
}

char		*ft_itoa(int n)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) * ft_ilen(n))) == NULL)
		return (NULL);
	if (n >= 0)
	{
		while (n != 0)
		{
			*--str = '0' + (n % 10);
			n /= 10;
		}
		return (str);
	}
	else
	{
		while (n != 0)
		{
			*--str = '0' - (n % 10);
			n /= 10;
		}
		*--str = '-';
	}
	return (str);
}
