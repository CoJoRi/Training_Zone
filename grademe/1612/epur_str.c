#include<unistd.h>

int isletter(char c)
{
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'a'))
		return (1);
	return (0);
}

int isblnk(char c)
{
	if ((c >= 8 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i] && isblnk(argv[1][i]))
				i++;
		while(argv[1][i])
		{
			while (argv[1][i] && !((argv[1][i] >= 8 && argv[1][i] <= 13) || (argv[1][i] == ' ')))
			{
				write(1, &argv[1][i], 1);
				i++;
			}			
			while (argv[1][i] && (isblnk(argv[1][i])))
				i++;
			if (isblnk(argv[1][i - 1]) && (argv[1][i]))
				write(1, " ", 1);



		}
	}
	write(1, "\n", 1);
	return (0);
}