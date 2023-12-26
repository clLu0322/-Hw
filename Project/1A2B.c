#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGITS 4  // �]�w�Ʀr�����


void generateRandomNumber(int answer[]) {  // �ͦ��H���Ʀr

	srand(time(NULL));
	for (int i = 0; i < DIGITS; ++i) {
		answer[i] = rand() % 10;
		for (int j = 0; j < i; j++) { // �T�O�Ʀr������
			if (answer[i] == answer[j]) {
				i--;
			}
		}
	}
}

// �ˬd�q���P���K�Ʀr��1A2B���p
void checkGuess(int guess[], int answer[], int* A, int* B) {
	*A = *B = 0;

	for (int i = 0; i < DIGITS; i++) {
		if (guess[i] == answer[i]) {
			(*A)++;
		}
		else {
			for (int j = 0; j < DIGITS; j++) {
				if (guess[i] == answer[j]) 
					(*B)++;	
			}
		}
	}
}

void main() {
	int answer[DIGITS];  // ���K�Ʀr
	int guess[DIGITS];   // ���a�q�����Ʀr
	int A, B;            
	int ctr = 0;    

	generateRandomNumber(answer); // �ͦ����K�Ʀr

	printf("�w��Ө�1A2B�C���I\n");
	printf("�q�@��%d��Ʀr�C\n", DIGITS);

	do {
		printf("�п�J�A���q���G");
		scanf("%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3]);

		checkGuess(guess, answer, &A, &B); // �ˬd�q�����G
		printf("%dA%dB\n", A, B); // ��X���G
		ctr++;

	} while (A!= DIGITS); // �@���`������q������

	printf("���ߧA�q��F�I���׬O %d%d%d%d\n", answer[0], answer[1], answer[2], answer[3]);
	printf("�A�`�@�q�F %d ���C\n", ctr);
	system("pause");
}