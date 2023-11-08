#include <stdio.h>

int Hw428()
{
	int code;
	int hours;
	int items;
	float hourly_wage;
	float wage;
	float weekly_sales;

	printf("Enter your employee code (Managers: 1,hourly workers: 2,commission workers: 3,pieceworkers: 4)");
	scanf("%d", &code);

	switch (code)
	{
	case 1:
		printf("You receive fixed weekly salary\n");
		break;

	case 2:
		printf("Enter # of hours worked: ");
		scanf("%d", &hours);
		printf("Enter hourly_wage: ");
		scanf("%f", &hourly_wage);
		if (hours > 40) 
			wage = (40 * hourly_wage) + (hours - 40)*hourly_wage*1.5;
		else
			wage = hours * hourly_wage;
		printf("You receive $ %.2f\n", wage);
		break;

	case 3:
		printf("Enter your weekly sales: ");
		scanf("%f", &weekly_sales);
		printf("you receive $%.2f\n", 250+0.057*weekly_sales);
		break;

	case 4:
		printf("How many items you produced?: ");
	    scanf("%d", &items);
		printf("you receive $%.2f\n", ((float)items * 9.5));//假設每件9.5元
		break;

	default:
		printf("Error code\n");
		break;
	}
	return 0;
}
