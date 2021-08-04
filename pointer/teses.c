#include <stdio.h>

int main() {

    int a[2] ={ 0, 1 };
    int const *b = a;

    *(int *)b = 200;

    printf("%d %d\n", a[0], a[1]);

    int c[2] ={ 0, 1 };

    printf("%d %d\n", c, c+1);
    printf("%d %d\n", *c, *(c+1));

}