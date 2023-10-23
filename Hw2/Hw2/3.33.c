#include <stdio.h>

int Hw333()
{
	int i, j;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if ((i == 0) || (i == 2) || (j == 0) || (j == 11))
				printf("+");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
