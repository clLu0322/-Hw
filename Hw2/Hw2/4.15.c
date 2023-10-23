#include <stdio.h>
#include <math.h>

int Hw415()
{
	double principal = 5000;
	double rate ;
	

	for (int i = 0; i < 5; i++)
	{
		rate = 0.1 + (i * 0.005);

		printf("Interest rate: %.2f%%\n", rate * 100);
		printf("%4s%21s\n", "Year", "Amount of deposit");

		for (unsigned int year = 1; year <= 15; ++year)
		{
			double amount = principal * pow(1.0 + rate, year);
			printf("%4u%21.2f\n", year, amount);
		}
		printf("\n");
	}
	return 0;
}
