// ����Ʈ(List)
// -> �ڷᰡ 1���������� ������ ����
// -> ����Ʈ�� ó���� ���� ������� ������ �ʿ���
// -> �迭�� �̿��� ����Ʈ -> arraylist
// -> ��带 �̿��� ����Ʈ -> linedlist

#include <stdio.h>

int size = 0;
// ����Ʈ�� �����͸� �߰��ϴ� �Լ�
void append(int* , int);// ����Ʈ�� ���� �߰��ϴ� �Լ�
void prepend(int*, int);// �տ� �߰��ϴ� �Լ�
void printlist(int*);// ����Ʈ�� ����ϴ� �Լ�
void insert(int*, int, int); // �߰��� �߰��ϴ� �Լ�

// ����Ʈ���� �����͸� �����ϴ� �Լ�
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
	for (int i = size-1; i >= 0; i--)	// ���� �ڷ� ��ĭ �� ����� for��
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
	// target�� ����Ʈ�� ���� ���
	if (position == -1)
		return;

	// ����Ʈ�� �ڷ� shift�ϴ� ���
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

	if (size == 0) return;	// �󸮽�Ʈ�� �� ����ó��

	int position = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			position = i;
			break;
		}
	}

	if (position == -1) return; 	// target�� ����Ʈ�� ���� ���

	// ����Ʈ�� ������ �̵�
	for (int i = position; i < size - 1; i++)
		arr[i] = arr[i + 1];
	arr[size - 1] = 0;
	size--;
	printlist(arr);
}