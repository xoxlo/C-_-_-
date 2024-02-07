#include "doublelinkedlist.h"

List* createlist() {
	List* l = (List*)malloc(sizeof(List));
	if (l != NULL) {
		l->head = l->tail = NULL;
	}
	return l;
}

int isempty(List* l) {
	if (l->head == NULL) return 1;
	else return 0;
}

Node* createnode(element value) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	// if (newnode == NULL) return NULL;
	if (newnode != NULL) {
		newnode->data = value;
		newnode->prelink = NULL;
		newnode->nextlink = NULL;
	}
	return newnode;
}

void printlist(List* l) {
	if (isempty(l)) { puts("EMPTY LIST"); return; }
	Node* current = (Node*)malloc(sizeof(Node));
	current = l->head;
	while (1) {
		if (current == l->tail) {
			printf("%d\n", current->data);
			break;
		}else
			printf("%d<->", current->data);
		current = current->nextlink;
	}
}
void init(List* l, element value) {
	Node* newnode = createnode(value);
	l->head = l->tail = newnode;
	printlist(l);
}
void append(List* l, element value) {
	if (isempty(l)) { init(l, value); return; }
	Node* newnode = createnode(value);

	l->tail->nextlink = newnode;	// 리스트 끝의 뒤에 새로운 노드를 연결, last of list, new node generated
	newnode->prelink = l->tail;		// 새로운 노드의 앞에 리스트의 끝을 연결, front of new node, last of list generated
	l->tail = newnode;				// 리스트의 끝을 새로운 노드로 변경
	
	printlist(l);
}
void prepend(List* l, element value) {
	if (isempty(l)) { init(l, value); return; }
	Node* newnode = createnode(value);	// 새로운 노드 생성
	l->head->prelink = newnode;	// 리스트의 처음의 앞에 새로운 노드 연결
	newnode->nextlink = l->head; // 새로운 노드의 뒤에 리스트의 처음을 연결
	l->head = newnode; // 리스트의 처음을 새로운 노드로 변경

	printlist(l);
}

void insert(List* l, element target, element value) {
	Node* current = l->head;
	while (1) {
		if (current == NULL) return;
		if (current->data == target) break;
		current = current->nextlink;
	}
	if (current == l->head) { prepend(l, value); return; }
	Node* newnode = createnode(value);
	// 이해 필요
	current->prelink->nextlink = newnode;
	newnode->prelink = current->prelink;
	
	newnode->nextlink = current;
	current->prelink = newnode;
	//
	
	// if (current == l->head) l->head = newnode;
	printlist(l);

}