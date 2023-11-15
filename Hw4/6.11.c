#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
	int a[SIZE] = {10,9,8,1,2,3,4,5,6,7};
	int i, j;
	int k;
	int ctr;

	for (i = 0; i < SIZE-1; i++)
	{
		ctr = 0;
		for (j = 0; j <= SIZE-2-i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
			else 
			{
				ctr += 1;
			}
		}
		

		printf("第%d次排序\n", i+1);
		for (k = 0; k <= SIZE-1; k++)
		{
			printf("%d  ", a[k]);
		}
		printf("\n");

		if (ctr >= SIZE - 1 - i)
		{
			printf("排序完成\n");
			system("pause");
			return 0;
		}

	}

	system("pause");
	return 0;
}
