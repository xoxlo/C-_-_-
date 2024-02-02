#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int* p1 = (int*)malloc(sizeof(int) * 5);
	// 초기화가 안됨
			// void* calloc(갯수, 바이트)

	int* p2 = (int*)calloc(5, sizeof(int));
	// 자동으로 0으로 초기화
	// 배열을 동적할당할 경우 calloc이 편리함

	for (int i = 0; i < 5; i++)
		printf("%d ", p1[i]);
	puts("");
	for (int i = 0; i < 5; i++)
		printf("%d ", p2[i]);
	return 0;
}