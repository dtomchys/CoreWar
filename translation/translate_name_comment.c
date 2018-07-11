#include "../asm.h"

void	ft_set_name_com(t_part *map, int op, t_parser *par)
{
	int i;
	int j;
	char *tmp;

	i = -1;
	while (par)
	{
		if (op == par->type)
		{
			while (par->line[++i])
			{
				tmp = ft_itoa_base(par->line[i], 16);
				j = ft_strlen(tmp) - 3;			
				while (tmp[++j])
					ft_set_symbol(map, ft_tolower(tmp[j]), !j && !tmp[j + 1] ? 1 : 0);
				free(tmp);
				tmp = NULL;
			}
			break ;
		}
		par = par->next;
	}
}