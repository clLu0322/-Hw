#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr;
	char ch;
	int cnt = 0;
	
	fptr = fopen("welcome.txt", "r");
	if (fptr != NULL)
	{
		while ((ch = getc(fptr)) != EOF)
		{
			printf("%c", ch);
			cnt++;
		}
		fclose(fptr);
		printf("\n�`�@��%d�Ӧr��\n", cnt);
	}
	else
		printf("�ɮ׶}�ҥ���!!\n");
	system("pause");
	return 0;
}