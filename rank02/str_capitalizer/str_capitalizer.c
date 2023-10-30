/* 
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
 */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	if (argc >= 2)
	{
		i = 0;
		j = 1;
		while (j < argc)
		{
			while (argv[j][i] != '\0')
			{
				if (argv[j][i] >= 'a' && argv[j][i] <= 'z' && (argv[j][i - 1] == ' ' || argv[j][i - 1] == '\t' || argv[j][i - 1] == '\0')) //if the first letter is miniscule
				{
					argv[j][i] = argv[j][i] - 32;
					write(1, &argv[j][i], 1);
				}
				else if (argv[j][i] >= 'A' && argv[j][i] <= 'Z' && (argv[j][i - 1] == ' ' || argv[j][i - 1] == '\t')) //if the first letter is mayuscule
					write(1, &argv[j][i], 1);
				else if (argv[j][i] >= 'A' && argv[j][i] <= 'Z' && argv[j][i - 1] != ' ' && argv[j][i - 1] != '\t' && argv[j][i - 1] != '\0') //if it is not the first letter of the word and is mayuscule
				{
					argv[j][i] = argv[j][i] + 32;
					write(1, &argv[j][i], 1);
				}
				else
					write(1, &argv[j][i], 1);
				i++;
			}
			i = 0;
			j++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}