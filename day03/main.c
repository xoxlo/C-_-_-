#include "sll.h"


int main() {

	append("apple");
	append("banana");
	append("orange");
	insert("banana", "grape");
	insert("orange", "cherry");
	insert("apple", "melon");
	// melon apple grape banana cherry orange
	printf("��� = %s \n", removelast());
	printf("��� = %s \n", removefirst());
	// apple grape banana cherry
	removemid("banana");
	removemid("cherry");
	removemid("apple");
	return 0;
}