#include "led.h"

void * led_green_task(void * arg) {
	printf("----- led_green thread start -----\n");
	
	int num = *(int *)arg;
	pinMode(GREEN_PIN_NUM, OUTPUT); // 동작모드 지정: output mode로 지정하겠다.
	
	for(int k = 0; k < num; k++) {
		digitalWrite(GREEN_PIN_NUM, HIGH);
		printf("led_green ON\n");
		sleep(2);
		digitalWrite(GREEN_PIN_NUM, LOW);
		printf("led_green OFF\n");
		sleep(2);
	}
	
	printf("----- led_green thread end -----\n");
	
	pthread_exit("green_thread end");
}