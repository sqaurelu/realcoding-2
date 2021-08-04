SRCS := func.c main.c
OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS := -c -Wall -g

three_files : $(OBJS)
	gcc -o $@ $^
	
.c.o :
	$(CC) $(CFLAGS) $<
	
clean : 
	-rm $(OBJS)
	-rm three_files

dep :
	gccmakedep $(SRCS)