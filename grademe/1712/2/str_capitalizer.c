#include <unistd.h>

char	minus(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	isletter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int isblnk(char c)
{
	if ((c >= 9 && c <= 13) || c== 32)
		return (1);
	return (0);
}
#include <stdio.h>
int main (int argc, char **argv)
{
	int i = 0;
	int j = 1;

	if (argc < 2)
	{
		write (1, "\n", 1);
		return (1);	
	}
 	while (argv[j])
	{
		while (argv[j][i])
		{
			argv[j][i] = minus(argv[j][i]);
			i++;
		}
		i = 0;
		while (argv[j][i])
		{
			if (isletter(argv[j][i]) && (i == 0 || isblnk(argv[j][i - 1])))
				argv[j][i] -= 32;
			write (1, &argv[j][i], 1);
			i++;
		}
		j++;
		i = 0;
		write (1, "\n", 1);
	}
	return (0);
}
