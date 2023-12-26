#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PrintBoard(char board[][15]) {  //�L�X�ѽL

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

bool check_x(char board[][15], int y, int x, char object) {   //�ˬdx�b��V�W�O�_�s�����l	
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

bool check_y(char board[][15], int y, int x, char object) {	//�ˬdy�b��V�W�O�_�s�����l
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

bool check_slash(char board[][15], int y, int x, char object) {	//�ˬdy=-x���u��V�W�O�_�s�����l
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

bool check_backslash(char board[][15], int y, int x, char object) {	//�ˬdy=x���u��V�W�O�_�s�����l
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

bool cheak(char board[][15], int y, int x, char object) { //�ˬd�Ҧ���V

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

	for (i = 0; i < 15; i++){         //��l�ƴѽL
		for (j = 0; j < 15; j++)
			board[i][j] = '.';
	}

	while (gamestatus != END){

		system("cls"); //�M��
		PrintBoard(board); 
		if (gamestatus == Gamer1){

			do{
				printf("�Ъ��a1��J�y��(y x): ");
				scanf("%d %d", &y, &x);
			} while ((board[y][x] != '.') || (y < 0) || (y > 14) || (x < 0) || (x > 14));

			board[y][x] = 'O';
			system("cls");
			PrintBoard(board);

			if ((cheak(board, y, x, 'O')) == 1) {
				printf("���a1�ӧQ\n");
				gamestatus = END;
			}
			else{
				gamestatus = Gamer2;
			}
		}
		else{
			do {
				printf("�Ъ��a2��J�y��(y x): ");
				scanf("%d %d", &y, &x);
			} while ((board[y][x] != '.') || (y < 0) || (y > 14) || (x < 0) || (x > 14));
			board[y][x] = 'X';
			system("cls");
			PrintBoard(board);

			if ((cheak(board, y, x, 'X')) == 1) {
				printf("���a2�ӧQ\n");
				gamestatus = END;
			}
			else {
				gamestatus = Gamer1;
			}
		}
	}
	system("pause");
}