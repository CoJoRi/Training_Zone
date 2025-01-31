#include<stdlib.h>
#include<unistd.h>
#include <stdio.h>

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}
int	isnbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int nb = 0;
	int i = 0;
	int sign = 1;

	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		{
			if(str[i] == '-')
				sign = -1;
			i++;
		}
	while (isnbr(str[i]))
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * sign);	
}

void	print_bits(unsigned char octet)
{
	char bit;
	int i = 7;

	while(i >= 0)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
	write(1, "\n", 1);
}

int power(int x)
{
	int res = 1;
	while(x--)
		res *= 2;
	return (res);
}

unsigned char reverse_bits3(unsigned char b)
{
	unsigned char	r = 0;
	unsigned		byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 7;
	int j = 0;
	unsigned char reversed = 0;

	while(j <= 7)
	{
		if ((octet >> j) & 1)
			reversed += power(i);
		j++;
		i--;
	}
	return (reversed);
}
unsigned char	reverse_bits2(unsigned char octet)
{
	int i = 7;
	unsigned char reversed = 0;

	while(i >= 0)
	{
		reversed |= ((octet >> i) & 1) << (7 - i);
		i--;
	}
	return (reversed);
}

unsigned char swapbit(unsigned char octet)
{
	return((octet >> 4)|(octet << 4));
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error: No input provided\n", 25);
		return (1);
	}
	char c = (char)ft_atoi(argv[1]);
	print_bits(c);
	//fflush(stdout); // Forcer l'affichage du tampon
	printf("%d\n", revbit(c));
	printf("%d\n", reverse_bits(c));
	printf("%d\n", reverse_bits2(c));
	printf("%d\n", reverse_bits3(c));

	
	return (0);
}