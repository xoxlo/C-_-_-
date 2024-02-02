#include <stdio.h>
#include <stdlib.h>

void status(int* a, int n, double* total, double* avg, double* max) {
	printf("%d명의 학생 점수를 입력하시오... \n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
		*total += (double)a[i];
	}
	*avg = *total / n;
	*max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > *max)
			*max = a[i];
	}
}
int main() {
	int n = 0;
	double total, avg, max;
	total = avg = max = 0.0;
	printf("학생 수 >> ");
	scanf_s("%d", &n);

	int* p = (int*)malloc(sizeof(int) * n);

	status(p, n, &total, &avg, &max);
	printf("\n할당 받은 배열의 크기 : %d\n", sizeof(int) * n);
	printf("학 생 수 : %d\n", n);
	printf("총    합 : %.2lf\n", total);
	printf("평    균 : %.2lf\n", avg);
	printf("최 대 값 : %.2lf\n", max);
	

	return 0;
}