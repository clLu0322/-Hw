#include<stdio.h>

int maximum(int x, int y, int z) {
	x = x > y ? x : y;
	return x > z ? x : z;
}

int main() {
	int x, y, z;
	printf("��J3�ӼƦr\n");
	scanf("%d%d%d", &x, &y, &z);
	printf("The maximum is : %d\n", maximum(x, y, z));
}