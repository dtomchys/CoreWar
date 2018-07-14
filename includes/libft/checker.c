/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:43:40 by nrepak            #+#    #+#             */
/*   Updated: 2018/07/13 15:44:20 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../asm.h"

static int ft_read(int fd, int fd1)
{
	char str[2];
	char str1[2];
	int a;
	int b;
	int error;
	int i = 0;

	error = 0;
	while (((a = read(fd, str, 1)) >= 0) && ((b = read(fd1, str1, 1)) >= 0))
	{ 
	i++;
		if (!a && !b && !error)
			return (ft_printf("%s\n", "OK"));
		else if (!a && !b)
			return (ft_printf("%s\n", "ERROR"));
		str[a] = '\0';
		str1[b] = '\0';
		if (str[0] != str1[0] && (error = 1))
		{
			ft_printf("line == %d: ", i / 16);
			ft_printf("%x != %x\n", str[0], str1[0]);
		}
	}
	if (error)
		return (ft_printf("%s\n", "ERROR"));
	if (a == -1 || b == -1)
		return (ft_printf("%s\n", "An error occurred in the read."));
	return (0);
}

int		main(int ac, char **av)
{
	int fd;
	int fd1;

	if (ac != 3)
		return (ft_printf("%s\n", "Usage: ./checker file_name1[.cor] file_name2[.cor]"));
	fd = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	if (ft_read(fd, fd1))
		return (0);
	write (1, "OK\n", 3);
	return (0);
}
