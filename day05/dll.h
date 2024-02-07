// dll.h
// 노드 리스트 구조체
// 함수 원형
// createnode() createlist() isempty()
// printlist() init() append() prepend()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	struct node* pre;
	char data[30];
	struct node* next;
};
typedef struct node Node;

typedef struct {
	Node* head;
	Node* tail;
}List;

List* createlist();
int isempty(List*);
Node* createnode(const char*);
void printlist(List*);
void init(List*, const char*);
void append(List*, const char*);
void prepend(List*, const char*);
void insert(List*, const char*, const char*);