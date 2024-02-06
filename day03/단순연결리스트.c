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
void insert(int, int); // ����Ʈ�� �߰��� �����ϴ� �Լ�
int removelast();	// ����Ʈ�� ���� �����ϴ� �Լ�
int removefirst();	// ����Ʈ�� ó���� �����ϴ� �Լ�
void removemid(int); // ����Ʈ�� ������ ���� �����ϴ� �Լ�

int main(){
	append(10);
	append(20);
	append(30);
	prepend(8);
	prepend(5);
	insert(20, 15);
	insert(30,25);
	insert(5, 3);
	printf("���� �� : %d\n", removelast());
	printf("���� �� : %d\n", removelast());
	printf("���� �� : %d\n", removefirst());
	printf("���� �� : %d\n", removefirst());
	removemid(15);
	removemid(8);
	removemid(20);
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

void insert(int target, int value) {
	Node* prenode = head; // �˻��� �ϱ� ���� Ŀ�������� ������
	if (head->data == target) {
		prepend(value);
		return;
	}
	while (1) {
		if (prenode == NULL) return;	// ����Ʈ �ȿ� ã�� ���� ���� ��� (����1)
		if (prenode->link->data == target) break;
		prenode = prenode->link;	// �����͸� �ڷ� �̵�
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// ���ο� ��� ����
	newnode->data = value;	// ���ο� ��忡 ���� ����
	newnode->link = prenode->link;	// ������ ��ġ�� �ִ� ��带 ����
	prenode->link = newnode;
	printlist();
}

int removelast() {
	int removeitem = tail->data;
	if (head == NULL)
		return -1;
	if (head == tail && head != NULL) {
		free(tail);
		head == tail == NULL;
		printlist();
		return removeitem;
	}

	// ����Ʈ�� ��尡 2�� �̻��� �� �����ϴ� �ڵ�
	Node* prenode = head;

	while (1) {	// Ŀ�� ������ �ϴ� �����͸� tail �� ���� �̵�
		if (prenode->link == tail) break;
		prenode = prenode->link;
	}
	free(tail);	// ����Ʈ�� ���� �����Ҵ� ����
	prenode->link = NULL;	// ���� ��尡 �ƹ���嵵 ����Ű�� �ʰ���
	tail = prenode;	// ����Ʈ�� ���� ����
	printlist();
	return removeitem;
}

int removefirst() {
	// (����1) �󸮽�Ʈ�� ��
	if (head == NULL) return -1;
	int removeitem = head->data;
	// (����2) ��尡 �ϳ��� ��
	if (head != NULL && head == tail) {
		free(head);
		head == tail == NULL;
	}
	Node* removenode = head;
	head = head->link;
	free(removenode);
	printlist();
	return removeitem;
}

void removemid(int target) {
	if (head->data == target) {
		removefirst();
		return;
	}
	Node* pre = head;
	while (1) {
		if (pre == NULL) break;
		if (pre->link->data == target) break;
		pre = pre->link;
	}
	if (pre->link == tail) {	// ������ ���� tail�� ��� (����1)
		removelast();
		return;
	}
	Node* removenode = pre->link;
	pre->link = removenode->link;
	free(removenode);
	printlist();
}