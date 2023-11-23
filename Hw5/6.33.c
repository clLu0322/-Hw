#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

size_t binarysearch(const int b[], int searchkey, size_t low, size_t high)
{

	size_t middle = (low + high) / 2;
	if (low == high) {
		if (searchkey == b[low])
		{
			return low;
		}
		else
		{
			return -1;
		}
	}

	if (searchkey == b[middle])
	{
		return middle;
	}
	else if (searchkey <= b[middle])
	{
		binarysearch(b, searchkey, low, middle - 1);
	}
	else
	{
		binarysearch(b, searchkey, middle + 1, high);
	}
}
int main() {
	int a[SIZE];
	int i;

	for (i = 0; i < SIZE; i++)
	{
		a[i] = 2 * i;
	}

	printf("Enter number between 0 and 28:  ");
	int key;
	scanf("%d", &key);

	size_t result = binarysearch(a, key, 0, SIZE - 1);
	if (result != -1)
	{
		printf("\n%d found at index %d\n", key, result);
	}
	else {
		printf("\n%d not found\n", key);
	}

}