#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��� ����ü
// �����Ͱ� ���ڿ�
typedef struct node {
	char data[30];	// ���� ���� �����ϱ� ���� ��� ����
	struct node* link;	// ���� ����� �ּҸ� �����ϱ� ���� ���
}Node;

void print(); // ����Ʈ ��� �Լ�
void init(const char*);	// �ʱ�ȭ �Լ�
void append(const char*); // ����Ʈ�� ���� �߰��ϴ� �Լ�
void prepend(const char*); // ����Ʈ�� ó���� �߰��ϴ� �Լ�
void insert(const char*, const char*);
char* removelast();
char* removefirst();
void removemid(const char*);