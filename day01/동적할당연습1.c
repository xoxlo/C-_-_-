#include <stdio.h>
#include <stdlib.h>


int main() {
	int n = 0;
	double total = 0.0;
	printf("�л��� >> ");
	scanf_s("%d", &n);
	int* c = (int*)calloc(n, sizeof(int));
	printf("%d���� �л��� ������ �Է� ...\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &c[i]);
		total += c[i];
	}
	printf("total = %.2lf", total);
	
}