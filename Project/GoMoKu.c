#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PrintBoard(char board[][15]) {  //印出棋盤

	printf("                         1 1 1 1\n");
	printf("   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4\n");
	for (int i = 0; i < 15; ++i) {
		printf("%2d ", i);
		for (int j = 0; j < 15; ++j) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

bool check_x(char board[][15], int y, int x, char object) {   //檢查x軸方向上是否連成五子	
	int ctr = 0;
	for (int i = x - 4; i <= x + 4; i++) {
		if (board[y][i] == object) {
			ctr++;
			if (ctr == 5) {
				break;
			}
		}
		else {
			ctr = 0;
		}
	}
	if (ctr >= 5) 
		return 1;
	else
		return 0;	
}

bool check_y(char board[][15], int y, int x, char object) {	//檢查y軸方向上是否連成五子
	int ctr = 0;
	for (int i = y - 4; i <= y + 4; i++) {
		if (board[i][x] == object) {
			ctr++;
			if (ctr == 5) {
				break;
			}
		}
		else {
			ctr = 0;
		}
	}
	if (ctr >= 5)
		return 1;
	else 
		return 0;
}

bool check_slash(char board[][15], int y, int x, char object) {	//檢查y=-x直線方向上是否連成五子
	int ctr = 0;
	for (int i = y - 4, j = x - 4; i <= y + 4; i++, j++) {
		if (board[i][j] == object) {
			ctr++;
			if (ctr == 5) {
				break;
			}
		}
		else {
			ctr = 0;
		}
	}
	if (ctr >= 5)
		return 1;
	else 
		return 0;
}

bool check_backslash(char board[][15], int y, int x, char object) {	//檢查y=x直線方向上是否連成五子
	int ctr = 0;
	for (int i = y + 4, j = x - 4; i >= y - 4; i--, j++) {
		if (board[i][j] == object) {
			ctr++;
			if (ctr == 5) {
				break;
			}
		}
		else {
			ctr = 0;
		}
	}
	if (ctr >= 5)
		return 1;
	else
		return 0;
}

bool cheak(char board[][15], int y, int x, char object) { //檢查所有方向

	if ((check_x(board, y, x, object)
		|| check_y(board, y, x, object)
		|| check_slash(board, y, x, object)
		|| check_backslash(board, y, x, object)) == 1)
		return 1;
	else
		return 0;
}


void main() {

	char board[15][15];
	int i, j;
	int x, y;

	enum Status { END, Gamer1, Gamer2 };
	enum Status gamestatus;
	gamestatus = Gamer1;

	for (i = 0; i < 15; i++){         //初始化棋盤
		for (j = 0; j < 15; j++)
			board[i][j] = '.';
	}

	while (gamestatus != END){

		system("cls"); //清空
		PrintBoard(board); 
		if (gamestatus == Gamer1){

			do{
				printf("請玩家1輸入座標(y x): ");
				scanf("%d %d", &y, &x);
			} while ((board[y][x] != '.') || (y < 0) || (y > 14) || (x < 0) || (x > 14));

			board[y][x] = 'O';
			system("cls");
			PrintBoard(board);

			if ((cheak(board, y, x, 'O')) == 1) {
				printf("玩家1勝利\n");
				gamestatus = END;
			}
			else{
				gamestatus = Gamer2;
			}
		}
		else{
			do {
				printf("請玩家2輸入座標(y x): ");
				scanf("%d %d", &y, &x);
			} while ((board[y][x] != '.') || (y < 0) || (y > 14) || (x < 0) || (x > 14));
			board[y][x] = 'X';
			system("cls");
			PrintBoard(board);

			if ((cheak(board, y, x, 'X')) == 1) {
				printf("玩家2勝利\n");
				gamestatus = END;
			}
			else {
				gamestatus = Gamer1;
			}
		}
	}
	system("pause");
}