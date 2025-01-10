#include <unistd.h>

void repeat(char c)
{
	int nb = 1;
	
	if(c >= 'A' && c <= 'Z')
		nb = (c - 'A') + 1;
	if(c >= 'a' && c <= 'z')
		nb = (c - 'a') + 1;
	while (nb)
	{
		write(1, &c, 1);
		nb--;
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		while(argv[1][i] != '\0')
		{
			repeat(argv[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}