#include "../asm.h"

static t_part	*ft_make_part(int len, int shift)
{
	int		i;
	t_part  *res;

	res = (t_part*)malloc(sizeof(t_part));
	res->len = len * 2 + len / 2 + 1;
	res->tok = (char*)malloc(sizeof(char) * res->len--);
	res->cur = 0;
	i = -1;
	while (++i < res->len)
	{
		if (i % 40 == shift)
			res->tok[i] = '\n';
		else if(i % 5 == 4)
			res->tok[i] = ' ';
		else
			res->tok[i] = '0';
	}
	res->tok[i] = '\0';
	return (res);
}

void	ft_make_map(t_map *map, int len_exe)
{
	int i;

	i = -1;
	while (++i < 7)
	{
		if (i == 6)
			map->map[i] = ft_make_part(len_exe, 39);
		else if (i == 1)
			map->map[i] = ft_make_part(PROG_NAME_LENGTH, 29);
		else if (i == 4)
			map->map[i] = ft_make_part(COMMENT_LENGTH, 9);
		else
			map->map[i] = ft_make_part(4, 29);
	}
	map->map[5]->tok[9] = '\n';
}