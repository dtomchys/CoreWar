#include "../asm.h"

static void	ft_set_param(t_part *tok, t_args *arg)
{
	int i;
	int dif;
	char *tmp;

	if (!arg)
		return ;
	tmp = ft_itoa_base(arg->value, 16);
	i = -1;
	dif = arg->arg_size * 2 - ft_strlen(tmp);
	dif = !dif ? 1 : dif;
	if (arg->value >= 0)
	{
		ft_set_symbol(tok, ft_tolower(tmp[++i]), dif);		
		while (tmp[++i])
			ft_set_symbol(tok, ft_tolower(tmp[i]), 0);
	}
	else
		while (tmp[++i])
			if ((unsigned long)i >= (ft_strlen(tmp) - arg->arg_size * 2))
				ft_set_symbol(tok, ft_tolower(tmp[i]), 0);	
	ft_set_param(tok, arg->next);
}

void		ft_set_exec(t_part *tok, t_parser *par)
{
	char *tmp;
	int	i;

	if (!par)
		return ;
	if (par->type == COMMAND)
	{
		tmp = ft_itoa_base(par->op, 16);
		ft_set_symbol(tok, ft_tolower(tmp[0]), 1);
		free(tmp);
		if (par->codage)
		{			
			i = -1;
			tmp = ft_itoa_base(par->codage, 16);
			while (tmp[++i])
				ft_set_symbol(tok, ft_tolower(tmp[i]), 0);
			free(tmp);
		}
		ft_set_param(tok, par->args);
	}
	ft_set_exec(tok, par->next);
}
