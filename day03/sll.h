#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체
// 데이터가 문자열
typedef struct node {
	char data[30];	// 실제 값을 저장하기 위한 멤버 변수
	struct node* link;	// 다음 노드의 주소를 저장하기 위한 멤버
}Node;

void print(); // 리스트 출력 함수
void init(const char*);	// 초기화 함수
void append(const char*); // 리스트의 끝에 추가하는 함수
void prepend(const char*); // 리스트의 처음에 추가하는 함수
void insert(const char*, const char*);
char* removelast();
char* removefirst();
void removemid(const char*);