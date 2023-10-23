#include <stdio.h>

int main() {
	int totalMillionPerDay, gasPerGallon, milePerGallon, parkFee, tollPerDay;
	printf("please enter your totalMillionPerDay\n");
	scanf("%d", &totalMillionPerDay);
	printf("please enter your gasPerGallon\n");
	scanf("%d", &gasPerGallon);
	printf("please enter your milePerGallon\n");
	scanf("%d", &milePerGallon);
	printf("please enter your parkFee\n");
	scanf("%d", &parkFee);
	printf("please enter your tollPerDay\n");
	scanf("%d", &tollPerDay);

	printf("You need to cost %d", (totalMillionPerDay / milePerGallon)*gasPerGallon + parkFee + tollPerDay);
}