#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int n) {
	int index = 0;
	printf("### �ʱ� 1���� ���� �迭 ###\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", arr[index]);
			index++;
		}
		puts("");
	}
	while (n != 0) {
		printf("���ο� ũ�� (���� : 0) : ");
		scanf_s("%d", &n);
		arr = realloc(arr, n * n * sizeof(int));
		for (int i = 0; i < sizeof(arr); i++)
			arr[i] = 0;
		if (n == 0)	break;
		else {
			arr = (int*)realloc(arr, n);
			printf("### ���Ҵ�� 1���� ���� �迭 ###\n");
			index = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf("%d ", arr[index]);
				}
				puts("");
			}
		}
	}
	free(arr);
}
int main() {
	int* arr = (int*)calloc(25, sizeof(int));
	print(arr, 5);
	return 0;
}