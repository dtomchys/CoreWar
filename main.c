/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:51:26 by dtomchys          #+#    #+#             */
/*   Updated: 2018/07/03 16:51:28 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_check_args(int argc)
{
	if (argc == 1)
	{
		write(1, "Usage: ./asm <sourcefile.s>\n", 28);
		return (-1);
	}
	return (0);
}

int				ft_create_cor(char *path, t_map *map)
{
	int i;
	char *tmp;

	tmp = ft_strcpy(ft_strnew(ft_strlen(path) + 2), path);
	ft_strcpy(ft_strstr(tmp, ".s"), ".cor");
	if ((g_fd = open(tmp, O_CREAT | O_TRUNC | O_WRONLY, 0666)) < 0)
		return (-1);
	ft_printf("Writing output program to %s\n", tmp);	
	free(tmp);
	tmp = NULL;
	i = -1;
	while (++i < 7)
	{
		ft_putstr_fd(map->map[i]->tok, g_fd);
	}
	close(g_fd);
	return (0);
}

static int		ft_open_file(char *name)
{
	if ((g_fd = open(name, O_RDONLY)) == -1)//ERROR CAN'T OPEN
		return (-1);
	else if (!g_fd)//ERROR EMPTY FILE
		return (-1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_parser *par;
	t_map	 *map;
	char 	 *line;

	g_last_line = 0;
	g_row = 0;
	g_file = 0;
	if (ft_check_args(argc)) 
		return (1);
	if (ft_open_file(argv[argc - 1]))
		return (1);
	par = ft_new_par();
	if (ft_get_info(par, &line) || g_file < 3)//ERROR NON ENOUGH TEXT IN FILE
		return (1);
	ft_count_codage(par);
	ft_get_param_size(par);
	if (ft_count_labels(par))
		return (1);//NO SUCH LABEL
	map = (t_map*)malloc(sizeof(t_map));
	ft_bzero(map, sizeof(map));
	ft_make_map(map, ft_len_exec(par));
	ft_translation(map, par);
	if (ft_create_cor(argv[argc - 1], map))
		return (-1);
	return (0);
}

//DON'T FORGET ABOUT NEW LINE AFTER ZORK.S
