// �迭����Ʈ(array list)�� ����
// -> ����Ʈ�� ó���̳� �߰��� �������� �����ϰų� ������ ��,
//    (���ҵ��� shift�ϴ�) ������尡 �߻�
// -> ������ ��� -> ���Ḯ��Ʈ
// ���Ḯ��Ʈ (linked list)
// -> �ܼ����Ḯ��Ʈ(simple linked list)
// -> ���߿��� ����Ʈ(double linked list)
// �迭 ����Ʈ -> �迭�� ���Ұ� ����Ʈ�� ��������
// ���� ����Ʈ -> ���(node)�� ����Ʈ�� �����ϴ� ���� -> ����ü�� ����

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;	// ���� ���� �����ϱ� ���� ��� ����
	struct node* link;	// ���� ����� �ּҸ� �����ϱ� ���� ���
};

typedef struct node Node;
Node* head = NULL, *tail = NULL;	// ����Ʈ�� ó���� �� ��带 ����ų ����

void printlist();		// ����Ʈ�� ����ϴ� �Լ�
void init(int);	// ����Ʈ �ʱ�ȭ �Լ�
void append(int);	// ����Ʈ�� ���� �߰��ϴ� �Լ�
void prepend(int);	// ����Ʈ�� ó���� �߰��ϴ� �Լ�

int main(){
	append(15);
	append(20);
	append(30);
	prepend(10);
	return 0;
}

void init(int value) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = value;
	newnode->link = NULL;
	head = tail = newnode;
	printlist();
}

void printlist() {
	if (head == NULL) { puts("EMPTY LIST"); return; }
	Node* current = head;
	while (1) {
		if (current == tail) {
			printf("%d\n", current->data);
			break;
		}
		else {
			printf("%d��", current->data);
		}
		current = current->link;
	}
}

void append(int value) {	// ��带 ����Ʈ�� ���� �߰�
	if (head == NULL) { // �󸮽�Ʈ�� ���,
		init(value);	// �ʱ�ȭ�ϰ�
		return;			// �Լ�����
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// ���ο� ��� ����
	newnode->data = value;	// data�ʵ忡 �߰��� ���� ����
	newnode->link = NULL;	// link�ʵ忡 NULL�� �ʱ�ȭ
	tail->link = newnode;	// ����Ʈ�� ���� ���ο� ��带 ����
	tail = newnode;			// ����Ʈ�� ���� ���ο� ���� ����
	printlist();
}

void prepend(int value) {
	if (head == NULL) { // �󸮽�Ʈ�� ���,
		init(value);	// �ʱ�ȭ�ϰ�
		return;			// �Լ�����
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// ���ο� ��� ����
	newnode->data = value;	// ���ο� ��忡 ���� ����
	newnode->link = head;	// ���ο� ����� ��ũ�� ����Ʈ�� ó���� ����
	head = newnode;			// ����Ʈ�� ó���� ���ο� ���� ����
	printlist();
}