#include "sll.h"

Node* head = NULL;
Node* tail = NULL;
// 리스트의 처음과 끝 노드를 가리킬 변수

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
			printf("%s→", current->data);
		}
		current = current->link;
	}
}

void append(const char* value) {	// 노드를 리스트의 끝에 추가
	if (head == NULL) { // 빈리스트인 경우,
		init(value);	// 초기화하고
		return;			// 함수종료
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// 새로운 노드 생성
	strcpy_s(newnode->data, 30, value);	// data필드에 추가할 값을 저장
	newnode->link = NULL;	// link필드에 NULL로 초기화
	tail->link = newnode;	// 리스트의 끝에 새로운 노드를 연결
	tail = newnode;			// 리스트의 끝은 새로운 노드로 지정
	print();
}

void prepend(const char* value) {
	if (head == NULL) { // 빈리스트인 경우,
		init(value);	// 초기화하고
		return;			// 함수종료
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// 새로운 노드 생성
	strcpy_s(newnode->data, 30, value);	// 새로운 노드에 값을 저장
	newnode->link = head;	// 새로운 노드의 링크에 리스트의 처음을 연결
	head = newnode;			// 리스트의 처음을 새로운 노드로 저장
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