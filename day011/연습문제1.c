#include <stdio.h>
#include <stdlib.h>

void status(int* a, int n, double* total, double* avg, double* max) {
	printf("%d���� �л� ������ �Է��Ͻÿ�... \n", n);
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
	printf("�л� �� >> ");
	scanf_s("%d", &n);

	int* p = (int*)malloc(sizeof(int) * n);

	status(p, n, &total, &avg, &max);
	printf("\n�Ҵ� ���� �迭�� ũ�� : %d\n", sizeof(int) * n);
	printf("�� �� �� : %d\n", n);
	printf("��    �� : %.2lf\n", total);
	printf("��    �� : %.2lf\n", avg);
	printf("�� �� �� : %.2lf\n", max);
	

	return 0;
}