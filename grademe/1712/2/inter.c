#include <unistd.h>

int strsearch(char *str, char c, int i)
{
	while (i >= 0)
	{
		if (c == str[i])
			return (1);
		i--;
	}
	return (0);
}

void rotone(char *stra, char *strb)
{
	int i = 0;
	int j = 0;

	while(stra[i])
	{
		while (strb[j])
		{
			if (stra[i] == strb[j])
			{
				if (!strsearch(stra, stra[i], i - 1))
					write (1, &stra[i], 1);
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		rotone(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}