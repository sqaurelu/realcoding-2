SRCS := led_main.c led_green.c led_yellow.c
OBJS := $(SRCS:.c=.o)

CC := gcc
CLFAGS := -c -Wall 

ledtest : $(OBJS)
	$(CC) -o $@ $^ -lwiringPi -lpthread
	
clean:
	-rm $(OBJS)
	-rm ledtest
	
dep:
	gccmakedep $(SRCS)