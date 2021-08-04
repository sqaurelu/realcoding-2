#include <stdio.h>

int main() {
    int a[10] ={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    void *b;
    long long *c; // c라고 하는 변수는 longlong을 가리키는 변수
    
    b = &a[0]; 
    c

    printf("%, %d\n", a, *a);
    printf("%x, %lld\n", c, *c);
    printf("%x, %lld\n", c+1, *(c+1));

    int const k = 100;
    
}


