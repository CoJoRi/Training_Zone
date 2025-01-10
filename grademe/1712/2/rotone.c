#include <unistd.h>

int is_letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('a' + ((c - 97) + 1) % 26);
	else if (c >= 'A' && c <= 'Z')
		return ('A' + ((c - 65) + 1) % 26);

	return (c);
}

int main(int argc, char **argv)
{
	int i = 0;
	char c;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			c = is_letter(argv[1][i++]);
			write(1,&c, 1);
		}


	}
	write(1, "\n", 1);
	return(0);
}