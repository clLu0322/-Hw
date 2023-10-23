#include <stdio.h>

int Hw317() 
{
	int a=0;
	float  b, c, d, e;

	printf("Enter account number(-1 to end): ");
	scanf("%d", &a);
	while (a != -1)
	{
		printf("Enter beginning balance: ");
		scanf("%f", &b);
		printf("Enter total charges: ");
		scanf("%f", &c);
		printf("Enter total credits: ");
		scanf("%f", &d);
		printf("Enter credit limit: ");
		scanf("%f", &e);

		if (e < (b + c - d))
		{
			printf("Account:\t%d\n", a);
			printf("credit limit:\t%.2f\n", e);
			printf("Balance:\t%.2f\n", (b + c - d));
			printf("Credit Limit Exceed\n");
		}
		printf("\n");

		printf("Enter account number(-1 to end): ");
		scanf("%d", &a);
	}


	return 0;
}
