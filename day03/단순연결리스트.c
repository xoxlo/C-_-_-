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
void insert(int, int); // 리스트의 중간에 삽입하는 함수
int removelast();	// 리스트의 끝을 삭제하는 함수
int removefirst();	// 리스트의 처음을 삭제하는 함수
void removemid(int); // 리스트의 지정한 값을 삭제하는 함수

int main(){
	append(10);
	append(20);
	append(30);
	prepend(8);
	prepend(5);
	insert(20, 15);
	insert(30,25);
	insert(5, 3);
	printf("지운 값 : %d\n", removelast());
	printf("지운 값 : %d\n", removelast());
	printf("지운 값 : %d\n", removefirst());
	printf("지운 값 : %d\n", removefirst());
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

void insert(int target, int value) {
	Node* prenode = head; // 검색을 하기 위한 커서역할의 포인터
	if (head->data == target) {
		prepend(value);
		return;
	}
	while (1) {
		if (prenode == NULL) return;	// 리스트 안에 찾는 값이 없는 경우 (예외1)
		if (prenode->link->data == target) break;
		prenode = prenode->link;	// 포인터를 뒤로 이동
	}
	Node* newnode = (Node*)malloc(sizeof(Node));	// 새로운 노드 생성
	newnode->data = value;	// 새로운 노드에 값을 저장
	newnode->link = prenode->link;	// 삽입할 위치에 있는 노드를 연결
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

	// 리스트의 노드가 2개 이상일 때 동작하는 코드
	Node* prenode = head;

	while (1) {	// 커서 역할을 하는 포인터를 tail 전 노드로 이동
		if (prenode->link == tail) break;
		prenode = prenode->link;
	}
	free(tail);	// 리스트의 끝을 동적할당 해제
	prenode->link = NULL;	// 이전 노드가 아무노드도 가리키지 않게함
	tail = prenode;	// 리스트의 끝을 변경
	printlist();
	return removeitem;
}

int removefirst() {
	// (예외1) 빈리스트일 때
	if (head == NULL) return -1;
	int removeitem = head->data;
	// (예외2) 노드가 하나일 때
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
	if (pre->link == tail) {	// 삭제할 값이 tail일 경우 (예외1)
		removelast();
		return;
	}
	Node* removenode = pre->link;
	pre->link = removenode->link;
	free(removenode);
	printlist();
}