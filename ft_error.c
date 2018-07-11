#include "asm.h"

/*
int 	ft_check_symbols(char x)
{
	if (s[g_x + 1] && ((s[g_x + 1] >= 97 && s[g_x + 1] <= 122) ||
	 	(s[g_x + 1] == 95) || (s[g_x + 1] >= 48 && s[g_x + 1] <= 57)))
		return (1);
	return (0);
}

int 	ft_check_lexical_err(char *s)
{
	while (s[g_x])// && s[g_x] != ';' && s[g_x] != '#')
	{
		if ((s[g_x] == '-' && s[g_x + 1] && (s[g_x + 1] < '0' || s[g_x + 1] > '9'))
			|| !(s[g_x] && ((s[g_x] >= 97 && s[g_x] <= 122) ||
	 	(s[g_x] == 95) || (s[g_x] >= 48 && s[g_x] <= 57))))
		{
			printf("Lexical error at [%i:%i]\n", g_y, g_x + 1);
			return (1);
		}
		g_x++;
	}
	return (0);
}


int		ft_check_type(char *s)
{
	if (s[g_x] == 'r' && s[g_x + 1] && s[g_x + 1] >= '0' && 
		s[g_x + 1] <= '9' && ft_atoi(s + g_x + 1) >= 0 && 
		ft_atoi(s + g_x + 1) <= 99)
		return (1);
	else if (s[g_x] == '%' && s[g_x + 1] && s[g_x + 1] == ':' && 
		s[g_x + 2] && ((s[g_x + 2] >= 97 && s[g_x + 2] <= 122) ||
	 	(s[g_x + 2] == 95) || (s[g_x + 2] >= 48 && s[g_x + 2] <= 57)))
	 	return (2);
	else if (s[g_x] == '%' && s[g_x + 1] && ((s[g_x + 1] >= '0' && 
		s[g_x + 1] <= '9') || ((s[g_x + 1] == '-') && s[g_x + 2] && 
		s[g_x + 2] >= '0' && s[g_x + 2] <= '9')))
		return (3);
	else if (s[g_x] == ':' && s[g_x + 1] && ((s[g_x + 1] >= 97 && s[g_x + 1] <= 122) ||
	 	(s[g_x + 1] == 95) || (s[g_x + 1] >= 48 && s[g_x + 1] <= 57)))
	 	return (4);
	 else if ((s[g_x] >= 97 && s[g_x] <= 122) ||
	 	(s[g_x] == 95) || (s[g_x] >= 48 && s[g_x] <= 57))
	 	return (6);
	 else if ((s[g_x] >= '0' && s[g_x] <= '9') || ((s[g_x] == '-') && s[g_x + 1] && 
		s[g_x + 1] >= '0' && s[g_x + 1] <= '9'))
		return (5);
	return (0);
}



int	ft_error_name_com(char *s, int i)
{
	int index;

	printf("%s %i\n", s, g_x);
	if (ft_check_lexical_err(s))
		return (0);
	if (i == 1)
	{
		index = ft_check_type(s);
		if (index == 1)
		{
			printf("Syntax error at token [TOKEN][%03i:%03i] REGISTER \"r", g_y, g_x + 1);
			while (s[++g_x] >= '0' && s[g_x] <= '9')// && s[g_x] != ';' && s[g_x] != '#')
				printf("%c", s[g_x]);
			printf("\"\n");
		}
		else if (index == 2)
		{
			printf("Syntax error at token [TOKEN][%03i:%03i] DIRECT_LABEL \"%%:", g_y, (g_x++) + 1);
			while (((s[++g_x] >= 97 && s[g_x] <= 122) || (s[g_x] == 95) || (s[g_x] >= 48 && s[g_x] <= 57)))
				printf("%c", s[g_x]);
			printf("\"\n");
		}
		else if (index == 3)
		{
			printf("Syntax error at token [TOKEN][%03i:%03i] DIRECT \"%%", g_y, (g_x++) + 1);
			if (s[g_x] == '-')
				printf("%c", s[g_x++]);
			while (s[g_x] >= '0' && s[g_x] <= '9')
				printf("%c", s[g_x++]);
			printf("\"\n");
		}
		else if (index == 4)
		{
			printf("Syntax error at token [TOKEN][%03i:%03i] INDIRECT_LABEL \":", g_y, g_x + 1);
			while (((s[++g_x] >= 97 && s[g_x] <= 122) || (s[g_x] == 95) || (s[g_x] >= 48 && s[g_x] <= 57)))
				printf("%c", s[g_x]);
			printf("\"\n");
		}
		else if (index == 5)
		{
			printf("Syntax error at token [TOKEN][%03i:%03i] INDIRECT \"", g_y, g_x + 1);
			if (s[g_x] == '-')
				printf("%c", s[g_x++]);
			while (s[g_x] >= '0' && s[g_x] <= '9')
				printf("%c", s[g_x++]);
			printf("\"\n");
		}
		else if (index == 6)
		{
			printf("Syntax error at token [TOKEN][%03i:%03i] INSTRUCTION \"", g_y, g_x + 1);
			while (((s[g_x] >= 97 && s[g_x] <= 122) || (s[g_x] == 95) || (s[g_x] >= 48 && s[g_x] <= 57)))
				printf("%c", s[g_x++]);
			printf("\"\n");
		}
	//	printf("HERE\n");
	}
	return  (0);
}	*/

int	ft_error(int i)
{
	if (i == 0)
		perror("\x1B[31mError with the type of file\033[0m"); // a directory instead of file
	else if (i == 1)
	{
		perror("\x1B[31mError opening the file\033[0m"); // the file does not exist
		close (g_fd);
	}
	else if (i == 2)
	{
		perror("\x1B[31mError: The file is empty\033[0m"); // якщо пустий файл - протестити!;
		close (g_fd);
	}
	else if (i > 2)
	{
		if (i == 3)
			write(2, "\x1B[32mNAME\033[0m error at line ", 28); // name problem
		else if (i == 4)
			write(2, "\x1B[33mCOMMENT\033[0m error at line ", 31); // comment problem
		ft_putnbr(g_row);
		ft_putstr("\n");
	}
	// else if (i == 5) 
	return (0);

}

