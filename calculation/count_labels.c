#include "../asm.h"

static int			ft_get_path_after(const char *s, t_parser *par)
{
	int 	res;
	t_label *tmp;

	res = 0;
	while (par)
	{
		tmp = par->label;
		while (tmp)
		{
			if (!ft_strncmp((char *)s, tmp->name, ft_strlen(tmp->name)))
				return (res);
			tmp = tmp->next;
		}
		res += par->size;
		par = par->next;
	}
	return (-1);
}

static int			ft_get_path(const char *s, int pos, t_parser *par)
{
	t_label *tmp;
	int i;
	int	fl;
	int res;

	i = -1;
	fl = 0;
	res = 0;
	while (par && ++i > -1)
	{
		tmp = par->label;
		while (!fl && tmp)
		{
			if (!ft_strncmp((char *)s, tmp->name, ft_strlen(tmp->name)))
				fl = 1;
			tmp = tmp->next;
		}
		if (fl && i < pos)
			res += par->size;
		if (i == pos)
			break ;
		par = par->next;
	}
	return ( fl ? res * -1 : ft_get_path_after(s, par));
}

int			ft_count_labels(t_parser *head)
{
	int    i;
	t_args *tmp;
	t_parser *par;

	par = head;
	i = -1;
	while (par && ++i > -1)
	{
		tmp = par->args;
		if (par->par)
			while (tmp)
			{
				if (tmp->val)
				{
					if ((tmp->value = ft_get_path(tmp->val, i, head)) == -1)//ERROR NON LABEL
						return (-1);
					free(tmp->val);
					tmp->val = NULL;
				}
				tmp = tmp->next;
			}
		par = par->next;
	}
	return (0);
}