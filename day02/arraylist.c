#include "arraylist.h"
int count = 0;

void printlist(char arr[][100]) {
	for (int i = 0; i < count; i++)
		printf("%s ", arr[i]);
	puts("");
}
void append(char arr[][100], const char* value) {
	int size = strlen(value) + 1;
	strcpy_s(arr[count], 100, value);
	count++;
	printlist(arr);
}
void prepend(char arr[][100], const char* value) {
	for (int i = count - 1; i >= 0; i--)	// ���� �ڷ� ��ĭ �� ����� for��
		strcpy_s(arr[i + 1], 100, arr[i]);
	strcpy_s(arr[0], 100, value);
	count++;
	printlist(arr);
}
void insert(char arr[][100], const char* target, const char* value) {
	int position = -1;
	for (int i = 0; i < count; i++) {
		if (strcmp(arr[i], target) == 0) {
			position = i;
			break;
		}
	}
	// target�� ����Ʈ�� ���� ���
	if (position == -1)
		return;

	// ����Ʈ�� �ڷ� shift�ϴ� ���
	for (int i = count - 1; i >= position; i--)
		strcpy_s(arr[i + 1], 100, arr[i]);
	strcpy_s(arr[position], 100, value);
	count++;
	printlist(arr);
}

char* removelast(char arr[][100]) {
	char removeitem[100] = "";
	strcpy_s(removeitem, 100, arr[count - 1]);
	strcpy_s(arr[count - 1], 100, "");
	count--;
	return removeitem;
}
char* removefirst(char arr[][100]) {
	char removeitem[100] = "";
	strcpy_s(removeitem, 100, arr[0]);
	for (int i = 0; i < count-1; i++)
		strcpy_s(arr[i], 100, arr[i+1]);
	count--;
	return removeitem;
}