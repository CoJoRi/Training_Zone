int	    is_power_of_2(unsigned int n)
{

	while ((n % 2 == 0) && (n != 0))
	{
		n /= 2;
	}
	if ( n == 1)
		return (1);
	return (0);}

/* #include <stdio.h>
int main (void)
{
	int i = 138;
	int b = is_power_of_2(i);
	printf("%d",b);
} */