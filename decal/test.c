#include <stdio.h>

int decal(int n)
{
    return ()
}

int main(void)
{
    /* 0000 0001 << 2 == 0000 0100 */
    int a = 1 << 2;
    /* 0010 1010 << 2 == 1010 1000 */
    int b = 42 << 2;

    printf("a = %d, b = %d\n", a, b);
    b = b >> 19;
    printf("a = %d, b = %d\n", a, b);

    return 0;
}