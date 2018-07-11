#include "../asm.h"

void	ft_set_len(t_part *tok, int len)
{
	char *tmp;
	int i;

	tmp = ft_itoa_base(len, 16);
	i = -1;
	ft_set_symbol(tok, ft_tolower(tmp[++i]), 8 - ft_strlen(tmp));
	while (tmp[++i])
		ft_set_symbol(tok, ft_tolower(tmp[i]), 0);
}
