// �޸𸮿� �Ҵ� (memory allocation)
// ���� �Ҵ�(static allocation)
// -> ������ Ÿ�ӿ� ������ ũŰ�� ����
// -> ���μ����� �޸� ���� �� ����, ������ ������ �Ҵ�
// ���� �Ҵ�(dynamic allocation)
// -> ��Ÿ�ӿ� ������ ũ�Ⱑ �����ǰ� �Ҵ�
// -> ���μ����� �޸� ���� �� �� ������ �Ҵ�


#include <stdio.h>
#include <stdlib.h>
int a; // �������� -> �����Ҵ�

int main() {
	
	a = 10;
	int b = 10; // �������� -> �����Ҵ�
	int b2 = 11;
	int* c = (int*)malloc(sizeof(int));	// -> �����Ҵ�
	*c = 10;

	printf("�������� a�� �ּ� : %p\n", &a);
	printf("�������� b�� �ּ� : %p\n", &b);
	printf("�������� b2�� �ּ� : %p\n", &b2);
	printf("�����Ҵ� c�� �ּ� : %p\n", c);

	return 0;
}

