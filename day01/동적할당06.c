#include <stdio.h>
#include <stdlib.h>

int main() {
	char* p = (char*)malloc(5);
	
	for (int i = 0; i < 5; i++)
		p[i] = 0;
	for (int i = 0; i < 5; i++)
		printf("%d ", p[i]);
	puts("");

		// void* realloc (���Ҵ��Ҹ޸��ּ�, ���Ҵ��� ũ��)
	p = (char*)realloc(p, 10);

	for (int i = 0; i < 10; i++)
		printf("%d ", p[i]);
	puts("");
	p = (char*)realloc(p, 3);

	for (int i = 0; i < 3; i++)
		printf("%d ", p[i]);

	return 0;
}