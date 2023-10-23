#include <stdio.h>

int Hw319()
{
	float a, b;
	int	c;
	
	printf("Enter loan principal (-1 to end): ");
	scanf("%f", &a);
	while (a != -1)
	{
		printf("Enter interest rate: ");
		scanf("%f", &b);
		printf("Enter term of the loan in days: ");
		scanf("%d", &c);
		printf("The interest charge is $%.2f\n\n", a*b*c / 365);
		printf("Enter loan principal (-1 to end): ");
		scanf("%f", &a);
	
	}
	return 0;
}
