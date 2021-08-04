#include <stdio.h>
#include <wiringPi.h>
// gcc ledTest.c -lwiringPi;
int main() {
    int i;
    if (wiringPiSetup()==-1) return -1;
    pinMode(29, OUTPUT); // 핀 모드를 29번으로 설정합니다. (BCM으로 21번이 wiringPi에서 29번이므로)

    for(i=0;i<5;i++) {
        digitalWrite(29, 1) ; // led를 켭니다. (1)
        delay(500); // 0.5초 지연
        digitalWrite(29, 0);
        delay(500); // 0.5초 지연
    }
}