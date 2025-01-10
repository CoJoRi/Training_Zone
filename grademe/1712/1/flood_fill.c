typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void	recur(char **tab, t_point size, int x, int y, char c)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y || tab[y][x] != c)
		return;
	tab[y][x] = 'F';

	//progagation recurcive dans tous les sens
	recur(tab, size, x + 1, y,c);
	recur(tab, size, x - 1, y,c);
	recur(tab, size, x, y + 1,c);
	recur(tab, size, x, y - 1,c);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	c = tab[begin.y][begin.x];
	recur(tab, size, begin.x, begin.y, c);
}
/* 
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}


int main(void)
{
	t_point size = {8, 5};

	char *zone[] = {
		"11111111",
		"10000001",
		"10010101",
		"10110001",
		"11101111",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {3, 1};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
} */
/* 	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	}; */