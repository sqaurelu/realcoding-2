#include "led.h"

void * led_yellow_task(void * arg) {
	printf("----- led_yellow thread start -----\n");
	
	int num = *(int *)arg;
	pinMode(YELLOW_PIN_NUM, OUTPUT); // 동작모드 지정: output mode로 지정하겠다.
	
	for(int k = 0; k < num; k++) {
		digitalWrite(YELLOW_PIN_NUM, HIGH);
		printf("led_yellow ON\n");
		sleep(3);
		digitalWrite(YELLOW_PIN_NUM, LOW);
		printf("led_yellow OFF\n");
		sleep(3);
	}
	
	printf("----- led_yellow thread end -----\n");
	
	pthread_exit("yellow_thread end");
}
