#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGITS 4  // 設定數字的位數


void generateRandomNumber(int answer[]) {  // 生成隨機數字

	srand(time(NULL));
	for (int i = 0; i < DIGITS; ++i) {
		answer[i] = rand() % 10;
		for (int j = 0; j < i; j++) { // 確保數字不重複
			if (answer[i] == answer[j]) {
				i--;
			}
		}
	}
}

// 檢查猜測與秘密數字的1A2B情況
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
	int answer[DIGITS];  // 秘密數字
	int guess[DIGITS];   // 玩家猜測的數字
	int A, B;            
	int ctr = 0;    

	generateRandomNumber(answer); // 生成秘密數字

	printf("歡迎來到1A2B遊戲！\n");
	printf("猜一個%d位數字。\n", DIGITS);

	do {
		printf("請輸入你的猜測：");
		scanf("%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3]);

		checkGuess(guess, answer, &A, &B); // 檢查猜測結果
		printf("%dA%dB\n", A, B); // 輸出結果
		ctr++;

	} while (A!= DIGITS); // 一直循環直到猜中答案

	printf("恭喜你猜對了！答案是 %d%d%d%d\n", answer[0], answer[1], answer[2], answer[3]);
	printf("你總共猜了 %d 次。\n", ctr);
	system("pause");
}