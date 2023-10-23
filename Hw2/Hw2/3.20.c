#include <stdio.h>

int Hw320()
{
	int a;
	float b,c;

	printf("Enter # of hours worked (-1 to end): ");
	scanf("%d", &a);
	while (a != -1)
	{
		printf("Enter hourly rate of the worker: ");
		scanf("%f", &b);
		if (a > 40)
			c = a * b + (b / 2)*(a - 40);
		else
			c = a * b;
	
		printf("Salary is $%.2f\n\n", c);
		printf("Enter # of hours worked (-1 to end): ");
		scanf("%d", &a);

	}
	return 0;
}
