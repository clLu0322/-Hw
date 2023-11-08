#include<stdio.h>

int gcd(int a, int b) //最大公因數
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a%b);
}

void main() {
	int a, b, Lcm;
	printf("請輸入二個數字：");
	scanf("%d%d", &a, &b);
	Lcm = (a * b) / gcd(a, b);
	printf("%d和%d的最小公倍數是：%d", a, b, Lcm);
}