#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int* p1 = (int*)malloc(sizeof(int) * 5);
	// �ʱ�ȭ�� �ȵ�
			// void* calloc(����, ����Ʈ)

	int* p2 = (int*)calloc(5, sizeof(int));
	// �ڵ����� 0���� �ʱ�ȭ
	// �迭�� �����Ҵ��� ��� calloc�� ����

	for (int i = 0; i < 5; i++)
		printf("%d ", p1[i]);
	puts("");
	for (int i = 0; i < 5; i++)
		printf("%d ", p2[i]);
	return 0;
}