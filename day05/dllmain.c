// dllmain.c ÆÄÀÏ

#include "dll.h"

int main() {
	List* li = createlist();
	
	append(li, "apple");
	append(li, "banana");
	append(li, "orange");
	prepend(li, "grape");
	prepend(li, "lemon");
	return 0;
}