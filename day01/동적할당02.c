#include <stdio.h>
#include <stdlib.h>	// Standard Library
// malloc이 정의된 헤더파일


int main() {

	double a;
	// void* malloc(바이트);
	double* pa = (double*)malloc(sizeof(double));
	*pa = 10.5;

	printf("%lf", *pa);
	
	int arr[5];
	int* p = (int*)malloc(sizeof(int) * 5);
	p[0] = 10;
	p[1] = 20;
	p[2] = 30;
	p[3] = 40;
	p[4] = 50;

	for (int i = 0; i < 5; i++) {
		printf("%d", p[i]);
	}

	return 0;
}

