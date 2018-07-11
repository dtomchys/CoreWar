#include "../asm.h"

static int						ft_check_coma(char *s)
{
	int i;
	int err;

	i = -1;
	err = 0;
	while (s[++i])
	{
		if (err == 2)
			return (-1);//ERROR KOMA NEXT TO KOMA
		if (s[i] == SEPARATOR_CHAR)
			err++;
		else
			err = 0;
	}
	return (s[i - 1] == ',' ? -1 : 0);//ERROR KOMA AT THE END
}

static int						ft_parse_param(char *s, t_parser *par)
{
	int i;
	int j;
	char **split;

	i = -1;
	if (ft_check_coma(s))
		return (-1);
	split = ft_strsplit(s, SEPARATOR_CHAR);
	while (split[++i])
	{
		j = 0;
		while (split[i][j] == ' ' || split[i][j] == '\t')
			j++;
		if (split[i][j] == 'r' && !ft_validate_reg(i, par, split[i] + j))
			;
		else if (split[i][j] == '%' && !ft_validate_dir(i, par, split[i] + j))
			;
		else if ((split[i][j] == ':' || ft_isdigit(split[i][j]) ||\
			split[i][j] == '-') && !ft_validate_ind(i, par, split[i] + j))
			;
		else
			return (-1);//ERROR UNKNOWN PARAMETER
	}
	//FREE SPLIT
	return (i > 3 ? -1 : 0);//ERROR MORE THAN 3 PARAM
}

int								ft_parse_command(char *s, t_parser *par)
{
	int	err;

	err = 0;
	if (ft_strnstr(s, "live", 4) && ST(4) && (par->op = 1) && (par->codage = 0) != -1)
		err = ft_parse_param(s + 4, par);
	else if (ft_strnstr(s, "ldi", 3) && ST(3) && (par->op = 10) && (par->codage = 1))
		err = ft_parse_param(s + 3, par);
	else if (ft_strnstr(s, "sti", 3) && ST(3) && (par->op = 11) && (par->codage = 1))
		err = ft_parse_param(s + 3, par);	
	else if (ft_strnstr(s, "ld", 2) && ST(2) && (par->op = 2) && (par->codage = 1))
		err = ft_parse_param(s + 2, par);	
	else if (ft_strnstr(s, "st", 2) && ST(2) && (par->op = 3) && (par->codage = 1))
		err = ft_parse_param(s + 2, par);	
	else if (ft_strnstr(s, "add", 3) && ST(3) && (par->op = 4) && (par->codage = 1))
		err = ft_parse_param(s + 3, par);	
	else if (ft_strnstr(s, "sub", 3) && ST(3) && (par->op = 5) && (par->codage = 1))
		err = ft_parse_param(s + 3, par);	
	else if (ft_strnstr(s, "and", 3) && ST(3) && (par->op = 6) && (par->codage = 1))
		err = ft_parse_param(s + 3, par);	
	else if (ft_strnstr(s, "or", 2) && ST(2) && (par->op = 7) && (par->codage = 1))
		err = ft_parse_param(s + 2, par);
	else if (ft_strnstr(s, "xor", 3) && ST(3) && (par->op = 8) && (par->codage = 1))
		err = ft_parse_param(s + 3, par);	
	else if (ft_strnstr(s, "zjmp", 4) && ST(4) && (par->op = 9) && (par->codage = 0) != 1)
		err = ft_parse_param(s + 4, par);	
	else if (ft_strnstr(s, "fork", 4) && ST(4) && (par->op = 12) && (par->codage = 0) != 1)
		err = ft_parse_param(s + 4, par);
	else if (ft_strnstr(s, "lldi", 4) && ST(4) && (par->op = 14) && (par->codage = 1))
		err = ft_parse_param(s + 4, par);		
	else if (ft_strnstr(s, "lld", 3) && ST(3) && (par->op = 13) && (par->codage = 1))
		err = ft_parse_param(s + 3, par);
	else if (ft_strnstr(s, "lfork", 5) && ST(5) && (par->op = 15) && (par->codage = 1) != 1)
		err = ft_parse_param(s + 5, par);
	else if (ft_strnstr(s, "aff", 3) && ST(3) && (par->op = 16) && (par->codage = 1))
		err = ft_parse_param(s + 3, par);
	else
		return (-1);//ERROR WRONG COMMAND OR NON SPACE AFTER COMMAND
	g_label = 0;
	return (err ? -1 : 0);
}