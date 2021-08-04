#include <stdio.h>

void func(int *p) {// call by reference
    int *q = p;
    *q = 100;
    q++;
    *q = 200;
}

int main() {
    int a = 1;
    int b= 2;

    int *pa, *pb, pp;

    pa = &a;
    pb = &b;
    pp = (int)pa; // pp에 a의 주소를 줌

    printf("%d %d\n", a, b);
    func(&b);
    printf("%d %d\n", *pa, *pb); // 1 2
    printf("%d %d %d\n", pa, pb, *(int *) pp); //주소값이
    // pp는 integer였는데 pp를 다시 integer의 pointer로 casting한 다음에 *로 값을 불렀더니 올바르게 나왔다.
}