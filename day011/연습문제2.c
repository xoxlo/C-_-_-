#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 1;
	int* arr = (int*)calloc(25,sizeof(int));

	print(arr, 5);

	for (int i = 0; i < n * n; i++)
		arr[i] = 0;
	int index = 0;


	void print(int* arr, n) {
		printf("### �ʱ� 1���� ���� �迭 ###\n");
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				printf("%d ", arr[index]);
				index++;
			}
			puts("");
		}
		while (n != 0) {
			scanf_s("%d", &n);
			arr = realloc(arr, n, n * n * sizeof(int));
			printf("���ο� ũ�� (���� : 0) : ");
			scanf_s("%d", &n);
			if (n == 0)	break;
			else {
				arr = (int*)realloc(arr, n);
				printf("### ���Ҵ�� 1���� ���� �迭 ###\n");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						printf("%d ", arr[i]);
					}
					puts("");
				}
			}
		}
		free(arr);
	}


	return 0;
}