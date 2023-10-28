/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);
*/

/* #include <stdio.h> */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
/* 	if (str == NULL)
		return (0); */
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/* int	main(void)
{
	char str[] = "ahoj";
	int num;

	num = ft_strlen(str);
	printf("%d\n", num);
	return (0);
} */
