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
	printf("�p��X��n����A�п�JX n\n");
	scanf("%lf%d", &x, &n);
	printf("%.2lf", pow(x, n));
}