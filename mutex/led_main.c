#include "led.h"


int ledOnOff(int arg)
{
	int i;
	pinMode(arg, OUTPUT); // 동작모드 지정: output mode로 지정하겠다.
	
	for(i=0; i<10; i++) { 
		digitalWrite(arg, HIGH); 
		printf("led_red ON\n");
		sleep(1);
		digitalWrite(arg, LOW);
		printf("led_red OFF\n");
		sleep(1);
	}
	return 0;
}

int main(int argc, char *argv[]) // gpio pin number를 입력 받는다(arg) : default가 wiring pi number임
{
	int input1, input2;
	pthread_t green_id;
	pthread_t yellow_id;
	
	printf("----- Main thread start -----\n");
	
	if(argc == 3) { // input이 2개인 경우
		input1 = atoi(argv[1]);
		input2 = atoi(argv[2]);
	} else if(argc != 1) {
		printf("WRONG INPUT\n");
		exit(-1);
	}
	wiringPiSetup(); // wiringPi의 준비작업
	
	if(argc < 2) { // 빨간색만 깜빡
		ledOnOff(RED_PIN_NUM);
	}
	else if(input1 == 1 && input2 == 5) { //1 5 => 초록색 2초간격 5회
		pthread_create(&green_id, NULL, led_green_task, &input2);
		ledOnOff(RED_PIN_NUM);
	}
	else if(input1 == 2 && input2 == 7) { //2 7
		pthread_create(&yellow_id, NULL, led_yellow_task, &input2);
		ledOnOff(RED_PIN_NUM);
	}
	else if(input1 == 3 && input2 == 6) { // 3 6
		pthread_create(&green_id, NULL, led_green_task, &input2);
		pthread_create(&yellow_id, NULL, led_yellow_task, &input2);
		ledOnOff(RED_PIN_NUM);
	}
	else {
		printf("NO OPTION\n");
		exit(-1);
	}
	
	printf("----- Main thread end -----\n");
	pthread_exit(NULL);
	return 0;
}
