#include<stdio.h>

void stringReverse(char *sPtr) {
	if (*sPtr == '\0') 
		return;
	stringReverse(sPtr + 1);
	printf("%c", *sPtr);
}

int EX636() {
	char s[50];
	printf("Enter a string: ");
	scanf("%s", s);
	stringReverse(&s);
	printf("\n");
}