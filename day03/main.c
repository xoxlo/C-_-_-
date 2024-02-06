#include "sll.h"


int main() {

	append("apple");
	append("banana");
	append("orange");
	insert("banana", "grape");
	insert("orange", "cherry");
	insert("apple", "melon");
	// melon apple grape banana cherry orange
	printf("지운값 = %s \n", removelast());
	printf("지운값 = %s \n", removefirst());
	// apple grape banana cherry
	removemid("banana");
	removemid("cherry");
	removemid("apple");
	return 0;
}