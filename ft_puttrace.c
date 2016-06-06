/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 16:40:44 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/06 15:03:03 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		openfile(char *file)
{
	return(open(file, O_RDWR | O_APPEND));
}

void	puttrace(char *file, char *str, int fd)
 {
     if (fd != -1)
     {
         ft_putendl_fd(str, fd);
         close(fd);
     }
 }

 void    puttracen(char *file, char *str,  int num, int fd)
 {
     if (fd != -1)
     {
         ft_putstr_fd(str, fd);
         ft_putstr_fd(" : ", fd);
         ft_putnbr_fd(num, fd);
         ft_putchar_fd('\n', fd);
         close(fd);
     }
 }
