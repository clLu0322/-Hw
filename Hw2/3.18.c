#include <stdio.h>

int Hw318() 
{
	float a, b;

	printf("Enter sales in dollars (-1 to end): ");
	scanf("%f", &a);
	while (a != -1)
	{
		printf("Salary is $%.2f\n\n", ((a / 100) * 9) + 200);
		printf("Enter sales in dollars (-1 to end): ");
		scanf("%f", &a);
	}

	return 0;
}
