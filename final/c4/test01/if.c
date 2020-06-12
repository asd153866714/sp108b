#include <stdio.h>

int main()
{
    int a,b,c;

    a = 1;
    b = 2;
    c = 0;

    if (a > b)
    {
        c = a;
    }
    else
    {
        c = b;
    }

    printf("c = %d\n", c);
    return 0;
}
