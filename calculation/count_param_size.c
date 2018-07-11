#include "../asm.h"

static int		ft_get_total(t_args *tmp, int res)
{
	if (!tmp)
		return (res);
	return (ft_get_total(tmp->next, res + tmp->arg_size));
}

void			ft_get_param_size(t_parser *par)
{
	while (par)
	{
		if (par->type == COMMAND)
			par->size = ft_get_total(par->args, 1 + (par->codage ? 1 : 0));
		par = par->next;
	}
}