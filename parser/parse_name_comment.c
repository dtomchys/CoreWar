#include "../asm.h"

int		ft_find_end(int i, char *s)
{
	while (s[i])
	{
		if (s[i] == '#' || s[i] == ';')
			return (1);		
		if (s[i] != ' ' && s[i] != '\t')
			break ;
		i++;
	}
	if (!s[i])
		return (1);
	else
		return (0);
}

static char *ft_get_last_piece(char *s)
{
	char *tmp;
	char *line;
	int	 err;
	int  i;

	while (!ft_strchr(s, '"') && (err = get_next_line(g_fd, &line)) == 1)
	{
		tmp = ft_strjoin(s, "\n");
		free(s);
		s = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	i = -1;
	while (s[++i])
		if (s[i] == '"')
			break ;
	if (!ft_find_end(i + 1, s))//ERROR comment without # or ;
		return (NULL);
	while (s[i])
		s[i++] = '\0';
	if (err != 1)//ERROR NON END QUOTE
		return (NULL);
	else
		return (s);
}

static char	*ft_get_part(char *op, char *s)
{
	int	 i;
	int	 j;
	int	 fl[2];

	i = -1;
	j = 0;
	ft_bzero(fl, sizeof(fl));
	while (s[++i] && !fl[1])
	{
		if (s[i] == '"')
			fl[fl[0] ? 1 : 0] = i;
		if (s[i] == op[j])
			j++;
		else if ((s[i] != ' ' && s[i] != '\t') && !fl[0])//ERROR ODD CHAR BEFORE "
			return(NULL);
	}
	if (fl[1] && !ft_find_end(fl[1] + 1, s)) //ERROR comment without # or ;
		return(NULL);
	else if ((size_t)j != ft_strlen(op))//ERROR  .<>name/comment
		return (NULL);
	else if (!fl[1]--) 
		return (ft_get_last_piece(ft_strncpy(ft_strnew(i - fl[0]), s + fl[0] + 1, i - fl[0])));
	else
		return(ft_strncpy(ft_strnew(fl[1] - fl[0] + 1), s + fl[0] + 1, fl[1] - fl[0]));
	return(0);
}

int	ft_get_name_com(char *line, t_parser *par, int *i)
{
	static int	fl[2];

	if (ft_strstr(line, "comment") && ++fl[0] && ++*i)
	{
		g_file++;
		par->type = COMMENT;
		if ((fl[0] > 1 || fl[1] > 1) ||\
		(par->line = ft_get_part(".comment" , line)) == NULL\
		|| ft_strlen(par->line) > COMMENT_LENGTH)//ERROR 2 comment || ERROR TOO LONG COMMENT
			return (-1); //
	}
	else if (ft_strstr(line, "name") && ++fl[1] && ++*i)
	{
		g_file++;
		par->type = NAME;
		if ((fl[0] > 1 || fl[1] > 1) ||\
		(par->line = ft_get_part(".name" , line)) == NULL\
		|| ft_strlen(par->line) > PROG_NAME_LENGTH)//ERROR 2 comment || ERROR TOO LONG NAME
			return (-1);
	}
	else if (!fl[0] || !fl[1])
		return (-1);
	return(0);
}