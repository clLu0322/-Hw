#include <stdio.h>

unsigned int fibonacci(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

void main()
{
	int a;
	printf("輸入數字N查看費氏數列第N個數字: ");
	scanf("%d", &a);
	printf("%d\n", fibonacci(a));
	system("pause");
}