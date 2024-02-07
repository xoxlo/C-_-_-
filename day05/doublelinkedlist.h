#include <stdio.h>
#include <stdlib.h>

typedef int element;
struct node {
	struct node* prelink; // 이전 노드의 주소를 저장
	element data; // 값을 저장
	struct node* nextlink; // 다음 노드의 주소를 저장
};
typedef struct node Node;

typedef struct {	// 리스트를 여러개 만들기 위해 구조체로 지정
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