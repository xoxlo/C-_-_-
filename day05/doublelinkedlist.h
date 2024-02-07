#include <stdio.h>
#include <stdlib.h>

typedef int element;
struct node {
	struct node* prelink; // ���� ����� �ּҸ� ����
	element data; // ���� ����
	struct node* nextlink; // ���� ����� �ּҸ� ����
};
typedef struct node Node;

typedef struct {	// ����Ʈ�� ������ ����� ���� ����ü�� ����
	Node* head;
	Node* tail;
}List;

List* createlist();
int isempty(List*);
Node* createnode(element);
void printlist(List*);
void init(List*, element);
void append(List*, element);
void prepend(List*, element);
void insert(List*, element, element);