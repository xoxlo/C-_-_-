#include <stdio.h>
#include <stdlib.h>

int main() {

	int size = 0;
	printf("�ʿ��� ������ �� >> ");
	scanf_s("%d", &size);

	// �迭�� ũ��� ������Ÿ�ӿ� ���� -> �迭�� ũ�⸦ ������ �� �� ����
	// int arr[size]; (x)
	int* arr = (int*)malloc(sizeof(int) * size);
	// heap�� �޸𸮴� �ʱ�ȭ�� ���� ������, garbage value(�����Ⱚ)�� �����
	for (int i = 0; i < size; i++)
		arr[i] = 0;
	
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[0]);

	free(arr); // �����Ҵ��� �޸𸮸� �����ϴ� �Լ�
	// free(�ּ�);

	return 0;
}