#include <stdio.h>
/* test code for input var */

struct test_struct{

	int a;
	int b;
	int c;

}TEST_struct;


int g_var1 = 0;
void exFunc(int * var);
int inputVarTest(int a){
	int ret = 0;
	
	if (a == 100 && g_var1 == 10) {
		ret = 100;
	}else if(a == 50 && g_var1 ==5){
		ret =50;
	}else {
		ret =-1;
	}
	
	return ret;
}
struct strc{
	unsigned char state;
};

int bitFunc(struct strc data){


	struct strc data2;
	if((data.state & 0x02) == 0x02){
		printf("state1 = %X\n",2);
		printf("state2 = %X\n",data.state);
		printf("state3 = %d\n",data.state);
	}else{
		printf("state4 = %X\n",0x02 & 0x02);
		printf("state5 = %X\n",data.state);
		printf("state6 = %d\n",data.state);
	}
	return 0;
}

/* test code for undefined func Stub */
int undefinedFunc(int arg);
int definedFunc(int arg){
	return (arg * 12) + (arg * 100);
}

void undefinedStubTest(int a)
{
	int j;
	int	l;

	j = undefinedFunc(l);
	if(j == 100 ){
		j=0;

	}else{
		j=1;
	}
}

/* test code for defined func Stub */
void definedStubTest(int a)
{
	int j, l;

	j = definedFunc(a);
	if(j == 112 ){
		j=0;
	}else if(j ==336){
		j=1;
	}else{
		j=2;
	}
}


/* Test code for void pointer */
struct S {
   int m1;
   float m2;
};

int VoidPtrTest(void* arg)
{
   int ret = 0;
   struct S *ptr = (struct S*)arg;
   if (ptr->m1 == 0) {
      ret = 0;
   }else{
      ret = 1;
   }
   return ret;
}

/* test code for static local var */
void staticVarTest(){
	static int a = 0;

	if(a==0){
		a++;
		return;
	}else if(a==1){
		a=3;
		return;
	}else if(a==3){
		a++;
		return;
	}

	return;
}

void funcCall(){
	testA();
	testB();
	testC();
}
/* test code for local var - call by reference */
void localVarTest(){
	int local_var =0;
	int flag = 0;
	exFunc(&local_var);
	if(local_var == 1){
		flag = 1;
	}else if(local_var ==2){
		flag = 2;
	}else{
		flag = 0;
	}
}

/* test code for Null Check */
struct data {
	int a;
	char *b;
};

int testMe(int a, int b , char c){
	return 0;
}
int pointerTest(struct data *pData)
{
	if(pData == 0){
		return -1;
	}else if(pData->a == 0){
		return 0;
	}else if (pData->a == 1){
		return 1;
	}
	pData->b = (char *)malloc(10);
	strcpy(pData->b, "mwyun");
}


#ifdef UNIT_TARGET
/* Test code for virtual memory */

#define READ_REG(ADDR) (*(volatile unsigned long*)(ADDR))
typedef struct strname{
	int a;
}AAA;
#define REG_BASE_ADDR 0xFFE40000U
#define (*(unsigned int *)AAA) 0xFFFF0230u
typedef unsigned char	uint8_t;			// unsigned  8-bits : begins with 'b'
typedef char			int8_t;			//   signed  8-bits : begins with 'c'
typedef unsigned int	uint16_t;			// unsigned 16-bits : begins with 'w'
typedef int				int16_t;			//   signed 16-bits : begins with 'i'
typedef unsigned long	uint32_t;			// unsigned 32-bits : begins with 'u'
typedef long			int32_t;			//   signed 32-bits : begins with 'l'
typedef float           float32_t;			// single precision IEEE 754 32-bits : begins with Capital
typedef double			int64_t;

extern volatile uint32_t ulAdcColumnWriteIndex;
int virtualMemoryTest1(){
	*(uint8_t *) ((((uint32_t)0x68000000) + (((uint32_t)0x2340) * 2)) + (ulAdcColumnWriteIndex * ((uint32_t)8) )+ 0)=100;
	/*if(READ_REG(REG_BASE_ADDR)==10){
		return 10;
	}*/
	return -1;
}


void virtualMemoryTest2(void)
{
    if(AAA&0x01==0x01){}
}

/* test code for infinite loop */
int infiniteLoopTest(int arg){
	
	while(1){
		return arg;
	}
}

#endif

int  ArrayTest(int a[10], int b[20])
{
	if (a[5] == 0x3 && b[10]== 0x4)
	{
		return 0;
	}else if( a[9]==0x1 || b[15] == 0x10)
	{
		return 0;
	}

	return 0;
}


