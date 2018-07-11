#include "../asm.h"

int		ft_len_exec(t_parser *par)
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

void	ft_set_symbol(t_part *tok, char i, int shift)
{
	if (tok->tok[tok->cur] == ' ' || tok->tok[tok->cur] == '\n')
		tok->cur++;
	shift += tok->cur;	
	while (tok->cur < shift)
	{
		if (tok->tok[tok->cur] == ' ' || tok->tok[tok->cur] == '\n')
			shift++;
		tok->cur++;
	}
	if (tok->tok[tok->cur] == ' ' || tok->tok[tok->cur] == '\n')
		tok->cur++;	
	tok->tok[tok->cur++] = i;
}

static void	ft_set_header(t_part *tok)
{
	tok->cur = 2;

	tok->tok[tok->cur++] = 'e';
	tok->tok[tok->cur++] = 'a';
	tok->cur++;
	tok->tok[tok->cur++] = '8';
	tok->tok[tok->cur++] = '3';
	tok->tok[tok->cur++] = 'f';
	tok->tok[tok->cur++] = '3';
}

void		ft_translation(t_map *map, t_parser *par)
{
	int i;

	i = -1;
	while (++i < 7)
	{
		if (!i)
			ft_set_header(map->map[i]);
		else if (i == 1)
			ft_set_name_com(map->map[i], NAME, par);
		else if (i == 4)
			ft_set_name_com(map->map[i], COMMENT, par);
		else if (i == 3)
			ft_set_len(map->map[i], ft_len_exec(par));
		else if (i == 6)
			ft_set_exec(map->map[i], par);
	}
}
