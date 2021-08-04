// func.c file
#include "func.h"
#include <stdio.h>

int func_name_or_id() {
#ifdef PRINT_ID
	printf("201723268\n");
	return 0;
#else
	printf("HwaJinLee\n");
	return 1;
#endif
}
