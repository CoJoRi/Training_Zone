#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int isprime(int n)
{
	int n2 = 2;
	if ( n == 1 || n == 2 || n == 3)
		return (n);
	while (n2 < n)
	{
		if ((n % n2) == 0)
			return (0);
		n2++;
	}
	return (n);
}

void fprime(int n)
{
	int prime = 1;

	if(isprime(n))
	{
		printf("%d", n);
		return;
	}
	while(prime <= n)
	{
		prime ++;
		if(isprime(prime) && (n % prime == 0))
		{
			printf("%d", prime);
			n /= prime;
			if (n > 1)
				printf("*");
			prime = 1;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	n = atoi(argv[1]);
		if (n > 0)
			fprime(n);
	}
	printf("\n");
	return (0);
}