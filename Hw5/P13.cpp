#include <stdio.h>
#include <stdlib.h>

void callbyReference(int &nPtr)
{
	nPtr = nPtr * nPtr * nPtr;
}

int main()
{
	int number = 5;
	printf("The original value of number is %d", number);

	callbyReference(number);

	printf("\nThe new value of number is %d\n", number);

	system("pause");
	return 0;
}