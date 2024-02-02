#include <stdio.h>
#include <stdlib.h>


int main() {
	int n = 0;
	double total = 0.0;
	printf("학생수 >> ");
	scanf_s("%d", &n);
	int* c = (int*)calloc(n, sizeof(int));
	printf("%d명의 학생의 점수를 입력 ...\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &c[i]);
		total += c[i];
	}
	printf("total = %.2lf", total);
	
}