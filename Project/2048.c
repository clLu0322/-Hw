#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int board[SIZE][SIZE];

void initializeBoard() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = 0;
		}
	}
}

void printBoard() {
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0) {
				printf("|    ");
			}
			else {
				printf("|%4d", board[i][j]);
			}
		}
		printf("|\n");
	}
}

void addTile() {  //尋找值為0的陣列，並隨機在其中一個填入2或4
	int emptyTiles[SIZE * SIZE][2];
	int count = 0;

	for (int i = 0; i < SIZE; ++i) {  //找值為0的陣列
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == 0) {
				emptyTiles[count][0] = i;
				emptyTiles[count][1] = j;
				count++;
			}
		}
	}

	if (count > 0) {
		int index = rand() % count;
		int value = (rand() % 2 + 1) * 2; // 抽 2 or 4
		int row = emptyTiles[index][0];
		int col = emptyTiles[index][1];
		board[row][col] = value;
	}
}  

void shift(int row[]) { // 從陣列最前端往開始，每個格都往前移，直到遇到0以外的數字
	int i, j;

	for (i = 0; i < SIZE - 1; ++i) {
		for (j = 0; j < SIZE - 1; ++j) {
			if (row[j] == 0) {
				row[j] = row[j + 1];
				row[j + 1] = 0;
			}
		}
	}
}

void merge(int row[]) {  // 前端和後端一樣，前端值x2，後端 = 0
	for (int i = 0; i < SIZE - 1; ++i) {
		if (row[i] == row[i + 1] && row[i] != 0) {
			row[i] *= 2;
			row[i + 1] = 0;
		}
	}
}

void moveLeft() {
	for (int i = 0; i < SIZE; ++i) {
		shift(board[i]);
		merge(board[i]);
		shift(board[i]);
	}
}

void moveRight() {
	for (int i = 0; i < SIZE; ++i) {
		int row[SIZE];
		for (int j = 0; j < SIZE; ++j) { // 把陣列倒過來
			row[j] = board[i][SIZE - 1 - j];
		}
		shift(row);
		merge(row);
		shift(row);
		for (int j = 0; j < SIZE; ++j) {
			board[i][SIZE - 1 - j] = row[j];
		}
	}
}

void moveUp() {
	for (int j = 0; j < SIZE; ++j) { 
		int col[SIZE];
		for (int i = 0; i < SIZE; ++i) {
			col[i] = board[i][j];
		}
		shift(col);
		merge(col);
		shift(col);
		for (int i = 0; i < SIZE; ++i) {
			board[i][j] = col[i];
		}
	}
}

void moveDown() {
	for (int j = 0; j < SIZE; ++j) {
		int col[SIZE];
		for (int i = 0; i < SIZE; ++i) {
			col[i] = board[SIZE - 1 - i][j];
		}
		shift(col);
		merge(col);
		shift(col);
		for (int i = 0; i < SIZE; ++i) {
			board[SIZE - 1 - i][j] = col[i];
		}
	}
}

int checkGameOver() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == 0) {
				return 0;
			}
			if ((j + 1 < SIZE) && (board[i][j] == board[i][j + 1])) {
				return 0;
			}
			if ((i + 1 < SIZE) && (board[i][j] == board[i + 1][j])) {
				return 0;
			}
		}
	}
	return 1;
}

void Start_2048() {

	int tmp[SIZE][SIZE];
	int i, j;
	int ctr;
	initializeBoard();
	srand(time(NULL));

	addTile();
	addTile();
	printBoard();

	char move;
	int gameOver = 0;

	while (!gameOver) {

		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++)
				tmp[i][j] = board[i][j];
		}
		ctr = 0;
		printf("\nEnter a move (W/A/S/D) or Q to quit: ");
		scanf(" %c", &move);

		switch (move) {
		case 'W':
		case 'w':
			moveUp();
			break;
		case 'A':
		case 'a':
			moveLeft();
			break;
		case 'S':
		case 's':
			moveDown();
			break;
		case 'D':
		case 'd':
			moveRight();
			break;
		case 'Q':
		case 'q':
			gameOver = 1;
			break;
		default:
			printf("Invalid move!\n");
			continue;
		}

		if (!gameOver) {
			system("cls");

			for (i = 0; i < SIZE; i++) {  // 如果陣列沒變，不加入新數字
				for (j = 0; j < SIZE; j++) {
					if (tmp[i][j] == board[i][j])
						ctr++;
				}
					
			}
			if(ctr<16)
				addTile();
	
			printBoard();
			if (checkGameOver()) {
				printf("\nGame over!\n");
				gameOver = 1;
			}
		}
	}
	system("pause");
}