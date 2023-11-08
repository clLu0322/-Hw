#include <stdio.h>

char Ex528(char word) {
	if (word >= 'A' && word <= 'Z')
		return word + 32;
	else if (word >= 'a' && word <= 'z')
		return word - 32;
	else 
		return '0';
}

int main() {
	char word;
	printf("Enter a char :");
	scanf("%c", &word);
	printf("Answer is %c", Ex528(word));
}