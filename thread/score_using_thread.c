#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h> // man thread_create

void *sthread1(void *arg) // *start_routine
{
	printf("---- Sthread1_Thread START ----\n");

	short sum = 0;
	for (int i = 0; i < 30; i++)
	{
		sum += *(short *)(arg + (2 * i));
		// printf("sum - %hd\n", sum);
	}

	double avg = 0;

	avg = sum / 30.0;

	printf("sum: %hd, average: %.2lf\n", sum, avg);

	printf("---- Sthread1_Thread END ----\n");
	pthread_exit(arg); // 여기서 child thread를 또 만들 수 있으니까 이렇게 쓰는게 조음
}

void *sthread2(void *arg) // *start_routine
{
	printf("---- Sthread2_Thread START ----\n");

	short score_temp[30];

	for (int i = 0; i < 30; i++)
	{ // put score into score_temp
		score_temp[i] = *(short *)(arg + (2 * i));
	}

	short temp = 0;
	for (int i = 0; i < 30; i++)
	{
		for (int k = 0; k < 30 - 1 - i; k++)
		{
			if (score_temp[k] < score_temp[k + 1])
			{
				temp = score_temp[k + 1];
				score_temp[k + 1] = score_temp[k];
				score_temp[k] = temp;
			}
		}
	}

	printf("SORTING SCORE\n");
	for (int i = 0; i < 30; i++)
	{
		printf("%d - %hd\n", i + 1, score_temp[i]);
	}

	printf("---- Sthread2_Thread END ----\n");
	pthread_exit(arg);
}

int main(void)
{
	pthread_t tid;
	int status1, status2;
	int i = 100;
	pthread_attr_t attr;

	short scores[30];

	FILE *fp = fopen("input2.txt", "r");

	for (int i = 0; i < 30; i++)
	{
		fscanf(fp, "%hd", &scores[i]);
		// printf("%hd\n", scores[i]);
	}

	printf("---- Main_Thread START ----\n");

	status1 = pthread_create(&tid, NULL, sthread1, (void *)&scores);
	status2 = pthread_create(&tid, NULL, sthread2, (void *)&scores);
	if (status1 != 0 || status2 != 0)
	{
		perror("thread create");
		exit(1);
	}

	fflush(fp);
	fclose(fp);
	printf("---- Main_Thread END ----\n");
	pthread_exit(NULL);
	return 0;
}