#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

int main() {
	int i, row;
	char** table;
	printf("�Է��� ���ڿ� ���� >> ");
	scanf_s("%d", &row);
	getchar(); // ����Ű ��ȿȭ

	table = (char**)calloc(row + 1, sizeof(char*));

	for (i = 0; i < row; i++)
		table[i] = (char*)calloc(MAX_SIZE, sizeof(char));
	table[i] = NULL;
	for (i = 0; i < row; i++){
		printf("%d ��° �̸� : ", i + 1);
		gets_s(table[i], MAX_SIZE);
	}
	puts("\n### ���ڿ� ��� ###\n");
	for (i = 0; i < row; i++)
		puts(table[i]);
	
	for (i = 0; i < row; i++)
		free(table[i]);

	free(table);

	return 0;
}