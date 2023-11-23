#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

int recursiveMaximum(int *array[], int size) {
	if (size == 1) 
		return array[0];
	else 
	{
		int max = recursiveMaximum(array, size - 1);
		if (max > array[size - 1])
			return max;
		else
			return array[size - 1];
	}
}

int main() {

	int a[SIZE];

	srand(time(0));
	for (int i = 0; i < SIZE; i++)
	{
		a[i] = rand() % 50;
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("The maximum of array a is ");
	printf("%d\n", recursiveMaximum(&a, SIZE));
}