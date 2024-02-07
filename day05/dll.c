#include "dll.h"

List* createlist() {
	List* l = (List*)malloc(sizeof(List));
	if (l == NULL) return NULL; // 동적 할당 실패시
	l->head = l->tail = NULL;
	return l;
}

int isempty(List* l) {
	if (l->head == NULL) return 1;
	else return 0;
}

Node* createnode(const char* value) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	strcpy_s(newnode->data, 30, value);
	newnode->pre = NULL;
	newnode->next = NULL;
	return newnode;
}

void printlist(List* l) {
	if (isempty(l)) { puts("EMPTY LIST"); return; }
	Node* current = (Node*)malloc(sizeof(Node));
	current = l->head;
	while (1) {
		if (current == l->tail) {
			printf("%s\n", current->data);
			break;
		}
		else
			printf("%s<->", current->data);
		current = current->next;
	}
}

void init(List* l, const char* value) {
	Node* newnode = createnode(value);
	l->head = l->tail = newnode;
	printlist(l);
}

void append(List* l, const char* value) {
	if (isempty(l)) { init(l, value); return; }
	Node* newnode = createnode(value);

	l->tail->next = newnode;
	newnode->pre = l->tail;
	l->tail = newnode;

	printlist(l);
}

void prepend(List* l, const char* value) {
	if (isempty(l)) { init(l, value); return; }
	Node* newnode = createnode(value);
	l->head->pre = newnode;
	newnode->next = l->head;
	l->head = newnode;

	printlist(l);
}