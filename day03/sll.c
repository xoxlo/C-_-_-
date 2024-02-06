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

void insert(const char* target, const char* value) {
	Node* prenode = head; // �˻��� �ϱ� ���� Ŀ�� ������ ������
	if (strcmp(head->data, target) == 0) { // �߰��� ���� HEAD�� ���� ���� �� (����1)
		prepend(value);
		return;
	}
	while (1) {
		if (prenode == NULL) // �˻��� ��尡 ���� �� (����2)
			return;
		if (strcmp(prenode->link->data, target) == 0)
			break;
		prenode = prenode->link;
	}
	Node* newnode = (Node*)malloc(sizeof(Node));
	strcpy_s(newnode->data, 30, value);	// data�ʵ忡 �߰��� ���� ����
	newnode->link = prenode->link;
	prenode->link = newnode;
	print();
}

char* removelast() {
	if (head == NULL) return NULL;
	char* removeitem = (char*)malloc(sizeof(30));

	strcpy_s(removeitem, 30, tail->data);
	
	if (head != NULL && head == tail) {
		free(head);
		head = tail = NULL;
		print();
		return removeitem;
	}
	Node* pre = head;
	while (1) {
		if (pre->link == tail) break;
		pre = pre->link;
	}
	free(tail);
	pre->link = NULL;
	tail = pre;
	print();
	return removeitem;
}

char* removefirst() {
	if (head == NULL) return NULL;
	char* removeitem = (char*)malloc(sizeof(30));
	strcpy_s(removeitem, 30, head->data);

	if (head != NULL && head == tail) {
		free(head);
		head == tail == NULL;
	}
	Node* removenode = head;
	head = head->link;
	free(removenode);
	print();
	return removeitem;
}

void removemid(const char* target) {
	if (strcmp(head->data, target) == 0) {
		removefirst();
		return;
	}
	Node* pre = head;
	while (1) {
		if (pre == NULL) break;
		if (strcmp(pre->link->data, target))
			break;
		pre = pre->link;
	}
	if (pre->link == tail) {
		removelast();
		return;
	}
	Node* removenode = pre->link;
	pre->link = removenode->link;
	free(removenode);
	print();
}