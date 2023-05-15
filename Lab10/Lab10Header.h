/*#include <windows.h>  // SetConsoleOutputCP, SetConsoleCP
#include <stdio.h>    //printf , fgets
#include <conio.h>    // getch
#include <string.h>   // strcpy, strncmp, strchr
//---------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
*/

#pragma once

#ifndef _MYHEADER_H_
#define _MYHEADER_H_

#include <iostream>
#include <cstdio>
using namespace std;
#pragma warning(disable : 4996)


struct node {
	int data;
	node* next;
};

struct stack {

	node* top;

	stack() {
		top = NULL;
	}
	void push(int x);
	int pop();
	bool isEmpty();
	void displayStack();
};

// Функция для объединения двух стеков в один
void mergeStacks(stack& s1, stack& s2, stack& s3);

#endif