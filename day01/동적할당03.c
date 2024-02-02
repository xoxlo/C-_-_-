#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char temp[100] = "";
	printf("문자열 입력 >> ");
	gets_s(temp, sizeof(temp));

	int size = strlen(temp);
	char* p = (char*)malloc(sizeof(char) * size);
	strcpy_s(p, size, temp);

	puts(p);

	return 0;
}