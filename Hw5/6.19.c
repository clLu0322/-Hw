#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int total[7][7] = { 0 };
	int a, b;
	int i, j;

	srand(time(0));

	for (i = 1; i < 36000; i++)
	{
		a = 1 + rand() % 6;
		b = 1 + rand() % 6;
		total[a][b] += 1;
	}

	printf("\t1\t2\t3\t4\t5\t6\n");
	for (i = 1; i <= 6; i++)
	{
		printf("%d",i);
		for (j = 1; j <= 6; j++)
		{	
			printf("\t%d", total[i][j]);
		}
		printf("\n");
		
	}
}