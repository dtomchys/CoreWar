#include "../asm.h"

int						ft_validate_label(char *s, int len, int j)
{
	int i;

	i = 0;
	while (i < len && s[i] && ((s[i] >= 97 && s[i] <= 122) ||\
	 (s[i] == 95) || (s[i] >= 48 && s[i] <= 57)))
		i++;
	while (j && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (i != len)
		return (-1);
	else
		return (0);
}

static int				ft_check_after_label(char *s, t_parser *par)
{
	int 	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (!s[i])
	{
		g_label = 1;
		return (0);
	}
	else
		return (ft_parse_command(s + i, par));
}

int 					ft_check_label(char *s, t_parser *par)
{
	int i;

	i = 0;
	while (s[i] != LABEL_CHAR)
		i++;
	if (!i)//ERROR NO LABEL BEFORE :
		return (-1);
	if (s[i - 1] != DIRECT_CHAR && s[i - 1] != SEPARATOR_CHAR && s[i - 1] != ' ' && s[i - 1] != '\t')
	{
		if (ft_validate_label(s, i, 0))//ERROR NON VALDATE LAABEL
			return (-1);
		if (!ft_new_label(&(par->label), s, i))//ERROR NON ALLOCATED LABEL
			return (-1);
		// printf("%s\n", par->label->name);
		return (ft_check_after_label(s + i + 1, par));
	}
	else
		return (ft_parse_command(s, par));
}