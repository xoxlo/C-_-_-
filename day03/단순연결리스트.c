// 배열리스트(array list)의 단점
// -> 리스트의 처음이나 중간에 아이템을 삽입하거나 삭제할 때,
//    (원소들을 shift하는) 오버헤드가 발생
// -> 개선된 방법 -> 연결리스트
// 연결리스트 (linked list)
// -> 단순연결리스트(simple linked list)
// -> 이중연결 리스트(double linked list)
// 배열 리스트 -> 배열의 원소가 리스트의 구성단위
// 연결 리스트 -> 노드(node)가 리스트를 구성하는 단위 -> 구조체로 정의

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;	// 실제 값을 저장하기 위한 멤버 변수
	struct node* link;	// 다음 노드의 주소를 저장하기 위한 멤버
};

typedef struct node Node;
Node* head = NULL, *tail = NULL;	// 리스트의 처음과 끝 노드를 가리킬 변수

void printlist();		// 리스트를 출력하는 함수
void init(int);	// 리스트 초기화 함수
void append(int);	// 리스트의 끝에 추가하는 함수
void prepend(int);	// 리스트의 처음에 추가하는 함수

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
			printf("%d→", current->data);
		}
		current = current->link;
	}
}

void append(int value) {	// 노드를 리스트의 끝에 추가
	if (head == NULL) { // 빈리스트인 경우,
		init(value);	// 초기화하고
		return;			// 함수종료
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// 새로운 노드 생성
	newnode->data = value;	// data필드에 추가할 값을 저장
	newnode->link = NULL;	// link필드에 NULL로 초기화
	tail->link = newnode;	// 리스트의 끝에 새로운 노드를 연결
	tail = newnode;			// 리스트의 끝은 새로운 노드로 지정
	printlist();
}

void prepend(int value) {
	if (head == NULL) { // 빈리스트인 경우,
		init(value);	// 초기화하고
		return;			// 함수종료
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// 새로운 노드 생성
	newnode->data = value;	// 새로운 노드에 값을 저장
	newnode->link = head;	// 새로운 노드의 링크에 리스트의 처음을 연결
	head = newnode;			// 리스트의 처음을 새로운 노드로 저장
	printlist();
}