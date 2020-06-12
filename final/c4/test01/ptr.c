#include <stdio.h>

int main(){
    int *p,a;
    a = 5;
    p = &a;
    printf("p = %d\n", *p);
    return 0;
}