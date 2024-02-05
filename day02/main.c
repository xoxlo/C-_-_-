#include "arraylist.h"

int main() {

	// char** arrlist[100];
	char arrlist[10][100];
	
	append(arrlist,"apple");
	append(arrlist,"banana");
	append(arrlist,"orange");
	prepend(arrlist,"grape");
	prepend(arrlist,"lemon");
	insert(arrlist, "apple", "pineapple");
	insert(arrlist, "grape", "blueberry");
	
	removelast(arrlist);
	removefirst(arrlist);

	printlist(arrlist);
	// blueberry grape pineapple apple banana

	removemid(arrlist, "pineapple");
	// blueberry grape apple banana
	removemid(arrlist, "blueberry");
	

	return 0;
}