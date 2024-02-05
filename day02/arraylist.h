// arraylist.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 사용자정의 헤더 파일
// 구조체, 함수들의 원형을 작성
// void printlist(char**);
void printlist(char[][100]);
// void append(char**, const char*);
void append(char[][100], const char*);
// void prepend(char**, const char*);
void prepend(char[][100], const char*);
void insert(char[][100], const char*, const char*);
char* removelast(char[][100]);
char* removefirst(char[][100]);
void removemid(char[][100], const char*);