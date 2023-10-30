/* Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$> */

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	start;
	int	end;
	int	i;

	i = 0;
	if (argc == 2)
	{
		// how long is the string?
		while (argv[1][i] != '\0')
			i++;
		while (i >= 0) // till we reach the begining of the string
		{
			while (argv[1][i] == '\0' || argv[1][i] == ' ' ||argv[1][i] == '\t')
				i--; // go to the end of the word
			end = i;
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--; // go to tha start of the word
			start = i + 1;
			int	flag;
			flag = start; // to check if write space or not
			while (start <= end) // to write the actual word
			{
				write(1, &argv[1][start], 1);
				start++;
			}
			if (flag != 0)
				write(1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	int	i;
// 	int	j;

// 	if (argc == 2)
// 	{
// 		char	*str;
// 		i = 0;
// 		j = 0;
// 		while (argv[1][i])
// 			i++;
// 		i--;
// 		str = malloc((sizeof(char) * (i + 1)));
// 		if (str ==	NULL)
// 			return (1);
// /* 		while (i != -1)
// 		{
// 			if (argv[1][i] == ' ' || argv[1][i] == '\t')
// 			{
// 				while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
// 				{
// 					str[j] = argv[1][i];
// 					i++;
// 					j++;
// 				}
// 				i = i - j - 1;
// 				j++;
// 			}
// 			if (argv[1][i] == ' ' || argv[1][i] == '\t')
// 			{
// 				str[j] = argv[1][i];
// 				j++;
// 				i--;
// 			}
// 			i--;
// 		} */
// 		while (i != -1)
// 		{
// 			// Skip leading spaces and tabs
// 			while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
// 			{
// 				i--;
// 			}

// 			if (i >= 0)
// 			{
// 				// Copy the word to str
// 				while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
// 				{
// 					str[j] = argv[1][i];
// 					i--;
// 					j++;
// 				}

// 				// Add a space after the word
// 				if (i >= 0)
// 				{
// 					str[j] = ' ';
// 					j++;
// 				}
// 			}
// 		}
// 		j = 0;
// 		while (str[j])
// 		{
// 			write(1, &str[j], 1);
// 			j++;
// 		}
// 		free(str);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }