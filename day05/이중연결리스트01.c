// single linked list의 단점
// -> 단향 검색만 가능
// 개선된 리스트 -> double linked list
// -> 양방향 검색이 가능
// -> 삽입 또는 삭제시 구현이 싱글에 비해 용이함


#include "doublelinkedlist.h"

int main() {
	List* l = createlist();

	append(l, 10);
	append(l, 20);
	append(l, 30);
	prepend(l, 8);
	prepend(l, 5);
	insert(l, 10, 9);
	insert(l, 5, 3);
	insert(l, 30, 23);
	return 0;
}