// single linked list�� ����
// -> ���� �˻��� ����
// ������ ����Ʈ -> double linked list
// -> ����� �˻��� ����
// -> ���� �Ǵ� ������ ������ �̱ۿ� ���� ������


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