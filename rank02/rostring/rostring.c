/* Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$> */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	start;
	int	end;
	int	flag;
	int	flag2;

	i = 0;
	start = 0;
	flag = 0;
	flag2 = 0;
	if (argc >= 2)
	{
		// position of the beginning of the first word
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		start = i;
		// position of the end of the first word
		while (argv[1][i] && argv[1][i] >= '!' && argv[1][i] <= '~')
			i++;
		end = i;
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		// printing output from the begining of the second word
		while (argv[1][i])
		{
			while (argv[1][i] && argv[1][i] >= '!' && argv[1][i] <= '~')
			{
				write(1, &argv[1][i], 1);
				flag2 = 1;
				i++;
			}
			// skip the spaces
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
			{
				flag = 1;
				i++;
			}
			if (flag == 1)
			{
				write(1, " ", 1);
				flag = 0;
			}
		}
		// printing the first word
		if (flag2 == 1 && argv[1][i - 1] != ' ')
			write(1, " ", 1);
		while (argv[1][start] && start < end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
