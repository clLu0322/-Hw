#include <stdio.h>

int Hw427() {
	int a, b, c;

	for (a = 1; a < 500; a++) 
	{
		for (b = 1; b < a; b++)
		{
			for (c = 1; c < b; c++) 
			{
				if (a * a == b * b + c * c)
				{
					printf("%d\t%d\t%d\n", c, b, a);
				}
			}
		}
	}

	return 0;
}
