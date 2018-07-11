#include "asm.h"

int	ft_error(int i)
{
	printf("%d\n", i);
	if (i == 0)
		perror("\x1B[31mError with the type of file\033[0m"); // a directory instead of file
	else if (i == 1)
		perror("\x1B[31mError opening the file\033[0m"); // the file does not exist
	else if (i == 2)
		perror("\x1B[31mError: The file is empty\033[0m"); // якщо пустий файл - протестити!;
	else if (i == 3)
		perror("\x1B[32mError: The name is too long(NAME LENGTH = 128).\033[0m");
	else if (i == 4)
		perror("\x1B[33mError: The comment is too long(COMMENT LENGTH = 2048).\033[0m");
	else if (i > 4)
	{
		if (i == 5)
			write(2, "\x1B[32mNAME\\COMMENT has a duplicate \033[0m error at line: ", 54); // name problem
		else if (i == 6)
			write(2, "\x1B[31mEntered COMMAND without COMMENT/NAME\033[0m error at line: ", 61); // comment problem
		else if (i == 7)
			write(2, "\x1B[31mInvalid COMMENT/NAME\033[0m error at line: ", 45);
		ft_putnbr(g_row);
		ft_putstr("\n");
	}
	if (i > 1)
		close(g_fd);
	return (-1);

}

