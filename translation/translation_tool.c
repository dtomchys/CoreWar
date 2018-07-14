/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_tool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:12:22 by dtomchys          #+#    #+#             */
/*   Updated: 2018/07/14 12:12:23 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

unsigned int	reverse_bits(int num, int bytes, int sign)
{
	char	tmp[4];
	int		i;

	i = -1;
	while (++i < bytes)
	{
		tmp[i] = num;
		num = num >> 8;
	}
	i = -1;
	num = 0;
	while (++i < bytes)
	{
		if (!sign && tmp[i] < 0)
		{
			tmp[i] -= 128;
			num |= tmp[i] + 128;
		}
		else
			num |= sign ? ~tmp[i] : tmp[i];
		if (i < bytes - 1)
			num = num << 8;
	}
	num = sign ? ~num : num;
	return (num);
}

int				ft_len_exec(t_parser *par)
{
	int res;

	res = 0;
	while (par)
	{
		if (par->type == COMMAND)
			res += par->size;
		par = par->next;
	}
	return (res);
}

static void		ft_set_header(int fd)
{
	int i;

	i = 0xf383ea << 8;
	write(fd, &i, 4);
}

void			ft_translation(int fd, t_parser *par)
{
	int i;
	int zero;

	i = -1;
	zero = 0;
	while (++i < 7)
	{
		if (!i)
			ft_set_header(fd);
		else if (i == 1)
			ft_set_name_com(fd, NAME, par);
		else if (i == 4)
			ft_set_name_com(fd, COMMENT, par);
		else if (i == 3)
			ft_set_len(fd, ft_len_exec(par));
		else if (i == 6)
			ft_set_exec(fd, par);
		else
			write(fd, &zero, 4);
	}
}
