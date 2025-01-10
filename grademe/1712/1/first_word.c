#include <unistd.h>

int	isblnk(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (10);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] && isblnk(argv[1][i]))
			i++;
		while (argv[1][i] && !(isblnk(argv[1][i])))
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}