#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h> 
#include <pthread.h> 

#define RED_PIN_NUM 1
#define GREEN_PIN_NUM 4
#define YELLOW_PIN_NUM 5


void * led_green_task(void * arg);
void * led_yellow_task(void * arg);

