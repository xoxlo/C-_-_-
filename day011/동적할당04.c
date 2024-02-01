#include <stdio.h>
#include <stdlib.h>

int main() {

	int size = 0;
	printf("필요한 변수의 수 >> ");
	scanf_s("%d", &size);

	// 배열의 크기는 컴파일타임에 결정 -> 배열의 크기를 변수로 할 수 없음
	// int arr[size]; (x)
	int* arr = (int*)malloc(sizeof(int) * size);
	// heap의 메모리는 초기화를 하지 않으면, garbage value(쓰레기값)이 저장됨
	for (int i = 0; i < size; i++)
		arr[i] = 0;
	
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[0]);

	free(arr); // 동적할당한 메모리를 해제하는 함수
	// free(주소);

	return 0;
}