#include "sll.h"

Node* head = NULL;
Node* tail = NULL;
// ����Ʈ�� ó���� �� ��带 ����ų ����

void init(const char* value) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	strcpy_s(newnode->data, 30, value);
	newnode->link = NULL;
	head = tail = newnode;
	print();
}

void print() {
	if (head == NULL) { puts("EMPTY LIST"); return; }
	Node* current = head;
	while (1) {
		if (current == tail) {
			printf("%s\n", current->data);
			break;
		}
		else {
			printf("%s��", current->data);
		}
		current = current->link;
	}
}

void append(const char* value) {	// ��带 ����Ʈ�� ���� �߰�
	if (head == NULL) { // �󸮽�Ʈ�� ���,
		init(value);	// �ʱ�ȭ�ϰ�
		return;			// �Լ�����
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// ���ο� ��� ����
	strcpy_s(newnode->data, 30, value);	// data�ʵ忡 �߰��� ���� ����
	newnode->link = NULL;	// link�ʵ忡 NULL�� �ʱ�ȭ
	tail->link = newnode;	// ����Ʈ�� ���� ���ο� ��带 ����
	tail = newnode;			// ����Ʈ�� ���� ���ο� ���� ����
	print();
}

void prepend(const char* value) {
	if (head == NULL) { // �󸮽�Ʈ�� ���,
		init(value);	// �ʱ�ȭ�ϰ�
		return;			// �Լ�����
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// ���ο� ��� ����
	strcpy_s(newnode->data, 30, value);	// ���ο� ��忡 ���� ����
	newnode->link = head;	// ���ο� ����� ��ũ�� ����Ʈ�� ó���� ����
	head = newnode;			// ����Ʈ�� ó���� ���ο� ���� ����
	print();
}

void removeNode(const char* value) {
	Node* cur = head;
	while (cur->link != NULL) {
		if (cur->data == value) {
			(cur+1)->link = cur->link;
		}
		else
			cur = cur->link;
	}
	print();
}