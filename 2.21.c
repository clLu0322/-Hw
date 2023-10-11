#include<stdio.h>

int main() {
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			if ((i != 0 && i != 9) && j > 0 && j < 9) 
				printf(" ");
			else 
				printf("*");
		}
		printf('\n');
	}

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if ((i == 0 || i == 8) && j >= 3 && j <= 5) 
				printf("*");
			else if ((i == 1 || i == 7) && (j == 1 || j == 7)) 
				printf("*");
			else if (i >= 2 && i <= 6 && (j == 0 || j == 8)) 
				printf("*");
			else 
				printf(" ");
		}
		printf('\n');
	}

	for (int i = 0;i < 9;++i) {
		for (int j = 0;j < 5;j++) {
			if (i == 1 && j == 2) 
				printf("*");
			else if (i == 2 && j >= 1 && j <= 3)
				printf("*");
			else if (i == 3) 
				printf("*");
			else if (j == 2)
				printf("*");
			else 
				printf(" ");
		}
		printf("\n");
	}

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if ((i == 0 || i == 8) && j == 4) 
				printf("*");
			else if ((i == 1 || i == 7) && (j == 3 || j == 5))
				printf("*");
			else if ((i == 2 || i == 6) && (j == 2 || j == 6)) 
				printf("*");
			else if ((i == 3 || i == 5) && (j == 1 || j == 7)) 
				printf("*");
			else if ((i == 4) && (j == 0 || j == 8))
				printf("*");
			else 
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
