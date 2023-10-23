#include<stdio.h>

int main() {
	int a, b;
	printf("Enter two integer\n");
	scanf("%d %d", &a, &b);
	if(a%b == 0)
		printf("First integer is the multiple of second integer");
	else
		printf("First integer is not the multiple of second integer");
}