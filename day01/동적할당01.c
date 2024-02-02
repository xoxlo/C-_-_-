// 메모리에 할당 (memory allocation)
// 정적 할당(static allocation)
// -> 컴파일 타임에 공간이 크키가 지정
// -> 프로세스의 메모리 영역 중 스택, 데이터 영역에 할당
// 동적 할당(dynamic allocation)
// -> 런타임에 공간의 크기가 결정되고 할당
// -> 프로세스의 메모리 영역 중 힙 영역에 할당


#include <stdio.h>
#include <stdlib.h>
int a; // 전역변수 -> 정적할당

int main() {
	
	a = 10;
	int b = 10; // 지역변수 -> 정적할당
	int b2 = 11;
	int* c = (int*)malloc(sizeof(int));	// -> 동적할당
	*c = 10;

	printf("전역변수 a의 주소 : %p\n", &a);
	printf("지역변수 b의 주소 : %p\n", &b);
	printf("지역변수 b2의 주소 : %p\n", &b2);
	printf("동적할당 c의 주소 : %p\n", c);

	return 0;
}

