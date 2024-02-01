#include <stdio.h>
#include <stdlib.h>

void print(int* arr, n) {
    int index = 0;
	printf("### 초기 1차원 동적 배열 ###\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", arr[index]);
			index++;
		}
		puts("");
	}
	while (n != 0) {
		printf("새로운 크기 (종료 : 0) : ");
		scanf("%d", &n);
        arr = realloc(arr, n * n * sizeof(int));
		if (n == 0)	break;
		else {
			arr = (int*)realloc(arr, n);
			printf("### 재할당된 1차원 동적 배열 ###\n");
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
	int* arr = (int*)calloc(25,sizeof(int));
	print(arr, 5);
	return 0;
}