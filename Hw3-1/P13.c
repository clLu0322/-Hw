#include<stdio.h>

double pow(double x, int n) {
	double sum = 1.00;
	for (int i = 0; i < n; i++)
		sum *= x;
	return sum;
}

int main() {
	double x;
	int  n;
	printf("計算X的n次方，請輸入X n\n");
	scanf("%lf%d", &x, &n);
	printf("%.2lf", pow(x, n));
}