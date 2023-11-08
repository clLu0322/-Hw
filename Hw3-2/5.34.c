#include <stdio.h>

int pow(int a, int b)
{
	if (b == 0)
		return 1;
	else
		return a * pow(a,b - 1);
}

void main()
{
	int base, exp;
	printf("輸入2個數字算指數: ");
	scanf("%d %d", &base, &exp);
	printf("%d", pow(base, exp));

}