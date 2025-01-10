#include <unistd.h>

char	minus(char c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

char	capitalize(char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

int isletter(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

int	isblnk(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	if (argc == 1)
		return(write(1, "\n", 1), 1);
	while (argv[j])
	{
		while(argv[j][i])
		{
			if (isletter(argv[j][i]))
				argv[j][i] = minus(argv[j][i]);
			i++;
		}
		i = 0;
		while(argv[j][i])
		{
			if (isletter(argv[j][i]) && (i == 0 || isblnk(argv[j][i - 1])))
				argv[j][i] = capitalize(argv[j][i]);
			i++;
		}
		putstr(argv[j]);
		write(1, "\n", 1);
		j++;
		i = 0;
	}
	return (0);
}


/* hile(argv[1][i])
	{
		while (isblnk(argv[1][i]))
			i++;
		if (isletter(argv[1][i]) && (i == 0 || isblnk(argv[1][i - 1])))
			capitalize(argv[1][i++])
		i++;

	} */