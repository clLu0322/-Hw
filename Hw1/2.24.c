#include<stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	if (a % 2 == 1)
		printf("This integer is odd.\n");
	else 
		printf("This integer is even.\n");

	return 0;
}