/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '_')
				j++;
			i++;
		}
		char *str;
		str = malloc(sizeof(char) * (i - j) + 1);
		if (str == NULL)
			return (0);
		i = 0;
		j = 0;
		while (argv[1][i])
		{
			if (argv[1][i] != '_')
			{
				if (argv[1][i - 1] == '_')
					str[j] = argv[1][i] - 32;
				else
					str[j] = argv[1][i];
				j++;
			}
			i++;
		}
		j = 0;
		while (str[j])
		{
			write(1, &str[j], 1);
			j++;
		}
		free(str);
	}
	write(1, "\n", 1);
	return (0);
}
