// 리스트(List)
// -> 자료가 1차원적으로 나열된 형태
// -> 리스트의 처음과 끝이 어딘지의 정보가 필요함
// -> 배열을 이용한 리스트 -> arraylist
// -> 노드를 이용한 리스트 -> linedlist

#include <stdio.h>

int size = 0;
// 리스트에 데이터를 추가하는 함수
void append(int* , int);// 리스트의 끝에 추가하는 함수
void prepend(int*, int);// 앞에 추가하는 함수
void printlist(int*);// 리스트를 출력하는 함수
void insert(int*, int, int); // 중간에 추가하는 함수

// 리스트에서 데이터를 삭제하는 함수
int removelast(int*);
int removefirst(int*);
void removemid(int*, int);

int main() {
	int arraylist[100];
	
	append(arraylist, 10);
	append(arraylist, 20);
	append(arraylist, 30);
	prepend(arraylist, 9);
	prepend(arraylist, 8);
	insert(arraylist, 20, 15);
	insert(arraylist, 15, 14);
	removelast(arraylist);
	removefirst(arraylist);
	removemid(arraylist, 14);
	removemid(arraylist, 15);
}
void prepend(int* arr, int value) {
	for (int i = size-1; i >= 0; i--)	// 값을 뒤로 한칸 씩 땡기는 for문
		arr[i + 1] = arr[i];
	arr[0] = value;
	size++;
	printlist(arr);
}
void printlist (int* arr) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	puts("");
}
void append(int* arr, int value) {
	arr[size] = value;
	size++;
	printlist(arr);
}

void insert(int* arr, int target, int value) {
	int position = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			position = i;
			break;
		}
	}
	// target이 리스트에 없는 경우
	if (position == -1)
		return;

	// 리스트를 뒤로 shift하는 경우
	for (int i = size - 1; i >= position; i--)
		arr[i + 1] = arr[i];
	arr[position] = value;
	size++;
	printlist(arr);
}
int removelast(int* arr) {
	arr[size - 1] = 0;
	size--;
	printlist(arr);
	return arr;
}
int removefirst(int* arr) {
	arr[0] = 0;
	for (int i = 0; i < size-1; i++)
		arr[i] = arr[i+1];
	size--;
	printlist(arr);
	return arr;
}

void removemid(int* arr, int target) {

	if (size == 0) return;	// 빈리스트일 때 예외처리

	int position = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			position = i;
			break;
		}
	}

	if (position == -1) return; 	// target이 리스트에 없는 경우

	// 리스트를 앞으로 이동
	for (int i = position; i < size - 1; i++)
		arr[i] = arr[i + 1];
	arr[size - 1] = 0;
	size--;
	printlist(arr);
}