#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("입력할 문자열 개수 : ");
	scanf_s("%d", &n);
	char** table = (char**)calloc(n, sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		table[i] = (char*)calloc(10, sizeof(char) * 10);
		printf("%d 번째 이름 : ", i + 1);
		scanf_s("%s", table[i]);
	}
	printf("### 문자열 출력 ###\n");
	for (int i = 0; i < n; i++)
		printf("%s\n", table[i]);
	for (int i = 0; i < n; i++)
		free(table[i]);
	free(table);
}