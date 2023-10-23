#include <stdio.h>

int Hw416()
{
	int i, j;


	printf("(A)\n");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			(i >= j) ?
				printf("%s", "*") :
				printf("%s", " ");
		}
		printf("\n");
	}

	printf("(B)\n");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			(j <= 9-i) ?
				printf("%s", "*") :
				printf("%s", " ");
		}
		printf("\n");
	}

	printf("(C)\n");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			(i <= j) ?
				printf("%s", "*") :
				printf("%s", " ");
		}
		printf("\n");
	}

	printf("(D)\n");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			(j >= 9 - i) ?
				printf("%s", "*") :
				printf("%s", " ");
		}
		printf("\n");
	}
}
